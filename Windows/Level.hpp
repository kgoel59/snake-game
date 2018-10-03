#ifndef _LEVEL_
#define _LEVEL_

#include "GameManager.hpp"

class Level:virtual public GameManager 
{
  public:
    void render();
};

#endif