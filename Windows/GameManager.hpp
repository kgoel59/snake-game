#ifndef _GAMEMANAGER_
#define _GAMEMANAGER_

#include <utility>
#include "Engine.hpp"
#include "Globals.hpp"
#include <vector>

class GameManager
{
protected:
    int score;
    std::pair<int,int> food;
	int screen_width, screen_height;

public:
    GameManager();
    void addFood();
    void renderFood();
};

#endif