//SNAKE GAME in C++ by CatBro

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<ncurses.h>
using namespace std;

//GameManager manages snake and Level. Player inherits snake and level (Multipath/Hybrid inheritence)

class GameManager
{
protected:
int screen_width,screen_height;
int score;
pair<int,int> food;
char SNAKE_CHAR ='*';
char LEVEL_CHAR ='#';
char FOOD_CHAR  ='F';
char UP         ='w';
char LEFT       ='a';
char DOWN       ='s';
char RIGHT      ='d';
int  difficulty = 100;    //Reduce it to increase difficulty;
public:
  GameManager():score(0){
    srand(time(nullptr));
    initscr();
    getmaxyx(stdscr,screen_height,screen_width);
    noecho();
    cbreak();
    //screen_width=80; screen_height=25  //Custom resolution
  }
  void addFood();
  void renderFood();
};

void GameManager::addFood()
{
      int x,y;
      y = rand()%screen_height;
      x = rand()%screen_width;
      while ((mvinch(y, x) & A_CHARTEXT) != ' ')
      {
          y = rand()%screen_height;
          x = rand()%screen_width;
      }
      food=pair<int,int>(x,y);
}

void GameManager::renderFood()
{
  move(food.second,food.first);
  addch(FOOD_CHAR);
}


class Level:virtual public GameManager
{
public:
  void render();
};

void Level::render()
{
  for (int i=0; i<screen_height; i++)
  {
      mvaddch(i, 0, LEVEL_CHAR);
      mvaddch(i, screen_width-1,LEVEL_CHAR);
  }
  for (int i=1; i<screen_width-1; i++)
  {
      mvaddch(0, i, LEVEL_CHAR);
      mvaddch(screen_height-1, i, LEVEL_CHAR);
  }
}

class Snake:virtual public GameManager
{
	int x,y;
	int bodyLength;
	char direction;
	vector<pair<int,int> > body;
public:
	Snake():x(20),y(10),bodyLength(2),direction('d'){
		for(int i=1;i<=bodyLength;i++)
		{
			body.push_back(pair<int,int>(x-i,y));
		}
	}
	void eat();
	void moveSnake();
	void setDirection(char);
	int  die();
	void render();
};


void Snake::moveSnake()
{
  if(!die())
 {
  if(x==food.first && y==food.second)
  {
    eat();
    addFood();
  }
	if(direction==UP)
	{
		for(int i=bodyLength-1;i>0;i--)
		{
			body[i]= body[i-1];
		}
		body[0]=pair<int,int>(x,y);
		y--;
	}
	if(direction==LEFT)
	{
		for(int i=bodyLength-1;i>0;i--)
		{
			body[i]= body[i-1];
		}
		body[0]=pair<int,int>(x,y);
		x--;
	}
	if(direction==DOWN)
	{
		for(int i=bodyLength-1;i>0;i--)
		{
			body[i]= body[i-1];
		}
		body[0]=pair<int,int>(x,y);
		y++;
	}
	if(direction==RIGHT)
	{
		for(int i=bodyLength-1;i>0;i--)
		{
			body[i]= body[i-1];
		}
		body[0]=pair<int,int>(x,y);
		x++;
	}
 }
 else
 {
     mvprintw(screen_height/2, screen_width/2,"GAMEOVER");
     move(screen_height/2+1,screen_width/2);
     printw("Score : %d\n",score);
 }
}

void Snake::setDirection(char ch)
{
  if(direction==UP && ch==DOWN || direction==DOWN && ch==UP  || direction==RIGHT && ch==LEFT  || direction==LEFT && ch==RIGHT )
  return;
  if(ch==UP || ch==LEFT || ch==DOWN || ch==RIGHT)
  direction=ch;
}

void Snake::eat()
{
  bodyLength++;
  score++;
  body.push_back(pair<int,int>(-1,-1));
  GameManager::addFood();
}

int Snake::die()
{
  if ((mvinch(y,x) & A_CHARTEXT) == LEVEL_CHAR || find(body.begin(),body.end(),pair<int,int>(x,y))!=body.end())
  return 1;
  else
    return 0;
}

void Snake::render()
{
  for(auto i=0;i<bodyLength;i++)
  {
      move(body[i].second, body[i].first);
      addch(SNAKE_CHAR);
  }
  move(y,x);
  addch(SNAKE_CHAR);
}


class Player:public Level,public Snake
{
public:
    void play();
};

void Player::play()
{
  Level::render();
  GameManager::addFood();
  GameManager::renderFood();
  Snake::moveSnake();
  Snake::render();
  refresh();

 char dir;
 while(1)
  {
    timeout(difficulty);
    dir=getch();
    Snake::setDirection(dir);
    clear();
    Level::render();
    GameManager::renderFood();
    Snake::moveSnake();
    Snake::render();
    refresh();
  }
  endwin();
}

int main()
{
  Player yourbro;
  yourbro.play();
  return 0;
}
