#include "Snake.hpp"

//Snake-----------------------------------------------------------

Snake::Snake() :Node("snake")
{
	x = 30;
	y = 10;
	score = 0;
	bodyLength = 2;
	direction = 'd';

	for (int i = 1; i <= bodyLength; i++)
	{
		body.push_back(pair<int, int>(x - i, y));
	}
}

void Snake::eat()
{
	score++;
	bodyLength++;
	body.push_back(pair<int, int>(-1, -1));
}

void Snake::moveSnake(Scene* scene,Food* food)
{
  if(!dead)
  {
    if(food->x == x && food->y == y)
    {
      eat();
	  food->addFood(scene);
    }

    if(direction==UP)
   	{
	  body.pop_back();
	  body.push_front(pair<int, int>(x, y--));
	}
    if(direction==LEFT)
	{
	  body.pop_back();
	  body.push_front(pair<int, int>(x--, y));
	}
	if(direction==DOWN)
	{
	  body.pop_back();
	  body.push_front(pair<int, int>(x, y++));
	}
	if(direction==RIGHT)
	{
	  body.pop_back();
	  body.push_front(pair<int, int>(x++, y));
	}

	if(die(scene))
	dead=true;
 }
  else
  {
	  scene->removeLayer("level");
	  scene->gameRenderer.clear();
	  scene->gameRenderer.mvprintW(GAME_WIDTH / 2 - 4, GAME_HEIGHT / 2, "GAME OVER");
	  scene->gameRenderer.mvprintW(GAME_WIDTH / 2 - 4, GAME_HEIGHT / 2 + 1, "SCORE : " + to_string(score));
	  scene->gameRenderer.refresh();
	  Sleep(2500);
	  exit(0);
  }
}

void Snake::setDirection(char ch)
{
  if(direction==UP && ch==DOWN || direction==DOWN && ch==UP  || direction==RIGHT && ch==LEFT  || direction==LEFT && ch==RIGHT )
  return;
  if(ch==UP || ch==LEFT || ch==DOWN || ch==RIGHT)
  direction=ch;
}

int Snake::die(Scene * scene)
{
  if ((scene->gameRenderer.moveXY(x,y) && scene->gameRenderer.readCh() == WALL_CHAR)  
	  || (find(body.begin(),body.end(),pair<int,int>(x,y)) != body.end()) )
  return 1;
  else
  return 0;
}

void Snake::reset()
{
	x = 30;
	y = 10;
	body.clear();
	bodyLength = 2;
	for (int i = 1; i <= bodyLength; i++)
	{
		body.push_back(pair<int, int>(x - i, y));
	}
	direction = 'd';
}

void Snake::render(Scene* scene)
{
  for(int i=0;i<bodyLength;i++)
  {
       scene->gameRenderer.mvprintCh(body[i].first, body[i].second,SNAKE_CHAR);
  }
       scene->gameRenderer.mvprintCh(x,y, HEAD_CHAR);
}
