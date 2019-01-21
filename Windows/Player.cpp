#include "Player.hpp"
#include <conio.h>

void Player::play()
{
  Level::addObstacle(0);
  Level::addObstacleLine(4,'h',-1,-1);
  Level::render();
  GameManager::addFood();
  GameManager::renderFood();
  Snake::moveSnake();
  Snake::render();
  GameEngine.refresh();

 char dir='\0';
 while(1)
  {
    Sleep(difficulty);
    if(_kbhit())
    dir=_getch();
	if (dir == 'q')
		break;
    Snake::setDirection(dir);
	GameEngine.clear();
	Level::render();
    GameManager::renderFood();
    Snake::moveSnake();
    Snake::render();
	GameEngine.refresh();
  }
}