#include <ctime>
#include "GameManager.hpp"

GameManager::GameManager()
{
    score=0;
    srand(time(nullptr));
}

void GameManager::addFood()
{
      int x,y;
      x = rand()%screen_width;
      y = rand()%screen_height;
      while ((GameEngine.moveXY(x,y) && GameEngine.readCh()!= ' '))
      {
          x = rand() % screen_width;
          y = rand() % screen_height;      
      }
      food=pair<int,int>(x,y);
}


void GameManager::renderFood()
{
    GameEngine.moveXY(food.first,food.second);
    GameEngine.printCh(FOOD_CHAR);
}
