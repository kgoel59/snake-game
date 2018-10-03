#include "Level.hpp"

void Level::render()
{
  for (int i=0; i<screen_height; i++)
  {
      GameEngine.mvprintCh(0, i, LEVEL_CHAR);
      GameEngine.mvprintCh(screen_width-1, i,LEVEL_CHAR);
  }
  for (int i=1; i<screen_width-1; i++)
  {
      GameEngine.mvprintCh(i, 0, LEVEL_CHAR);
     GameEngine.mvprintCh(i, screen_height-1, LEVEL_CHAR);
  }
}