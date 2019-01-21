#ifndef _LEVEL_
#define _LEVEL_

#include "GameManager.hpp"

class Level:virtual public GameManager 
{
  std::vector<std::pair<int, int> > obstacles;
  public:
	void addObstacle(int);
	void addObstacleLine(int,char,int,int);
    void render();
};

#endif