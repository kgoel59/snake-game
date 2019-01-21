#include "Level.hpp"

void Level::addObstacle(int num)
{
	while (num--)
	{
		int x, y;
		x = rand() % screen_width;
		y = rand() % screen_height;
		while ((GameEngine.moveXY(x, y) && GameEngine.readCh() != ' '))
		{
			x = rand() % screen_width;
			y = rand() % screen_height;
		}
		obstacles.push_back(std::pair<int, int>(x, y));
	}
}

void Level::addObstacleLine(int length,char type,int p=-1,int q=-1)
{
	if (length != 0)
	{
		if (p < 0 && q < 0)
		{
			p = rand() % screen_width;
			q = rand() % screen_height;
			while ((GameEngine.moveXY(p, q) && GameEngine.readCh() != ' '))
			{
				p = rand() % screen_width;
				q = rand() % screen_height;
			}
			obstacles.push_back(std::pair<int, int>(p, q));
		}
		else
		{
			if (type == 'h')
			{
				if (GameEngine.moveXY(++p, q) && GameEngine.readCh() != ' ')
				{
					obstacles.push_back(std::pair<int, int>(p, q));
					addObstacleLine(--length, type, p, q);
				}
			}
			else if (type == 'v')
			{
				if (GameEngine.moveXY(p, ++q) && GameEngine.readCh() != ' ')
				{
					obstacles.push_back(std::pair<int, int>(p, q));
					addObstacleLine(--length, type, p, q);
				}
			}
			else
				addObstacleLine(length, type, -1, -1);
		}
	}
}

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

  for (auto i = obstacles.begin(); i != obstacles.end(); i++)
  {
	  GameEngine.moveXY((*i).first, (*i).second);
	  GameEngine.printCh(OBSTACLE_CHAR);
  }
}