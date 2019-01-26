#pragma once

#include "SceneGraph.hpp"
#include "Globals.hpp"
#include "Level.hpp"

#include <deque>
#include <utility>
#include <algorithm>

using std::deque;
using std::pair;
using std::find;
using std::to_string;

class Snake:public Node
{
public:

	int x,y;
	int bodyLength;
	char direction;
	bool dead=false;
	deque <pair<int,int> > body;

public:
	
	int score;

	Snake();
	void eat();
	void moveSnake(Scene* scene,Food* food);
	void setDirection(char);
	int  die(Scene* scene);
	void reset();
	void render(Scene* scene);
};
