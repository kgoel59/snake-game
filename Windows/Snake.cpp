#include <sstream>
#include <algorithm>
#include "Snake.hpp"

using std::stringstream;
using std::find;

void Snake::moveSnake()
{
 if(!dead)
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

	if(die())
	dead=true;
 }
 else
 {
     GameEngine.mvprintW(screen_width/2, screen_height/2,"GAMEOVER");
     GameEngine.moveXY(screen_width/2,screen_height/2+1);
     stringstream s;
	 s << "Score :" << score;
     GameEngine.printW(s.str());
	 GameEngine.mvprintW(screen_width / 2, screen_height / 2 + 2, "Press q to quit");
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
  if ((GameEngine.moveXY(x,y) && GameEngine.readCh() == LEVEL_CHAR) || find(body.begin(),body.end(),pair<int,int>(x,y))!=body.end())
  return 1;
  else
	return 0;
}

void Snake::render()
{
  for(auto i=0;i<bodyLength;i++)
  {
      GameEngine.moveXY(body[i].first, body[i].second);
      GameEngine.printCh(SNAKE_CHAR);
  }
  GameEngine.moveXY(x,y);
  GameEngine.printCh(SNAKE_CHAR);
}
