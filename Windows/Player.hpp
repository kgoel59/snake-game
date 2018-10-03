#ifndef _PLAYER_
#define _PLAYER_

#include "Level.hpp"
#include "Snake.hpp"

class Player:public Level,public Snake
{
public:
    void play();
};

#endif