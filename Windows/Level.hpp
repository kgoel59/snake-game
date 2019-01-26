#pragma once

#include "SceneGraph.hpp"
#include "Globals.hpp"

#include <fstream>
#include <vector>

using std::ifstream;
using std::vector;

class Level;
class Stage;
class Food;

class Level : public Layer
{
	Stage *stage;

public:

	Level();
	void loadStage(string filename);

};

class Stage : public Node
{
public:
   
	string *stage = new string[GAME_HEIGHT];

	Stage();
	~Stage();
	void render(Scene* scene);
};

class Food :public Node
{
public:

	int x, y;

	Food();
	void addFood(Scene *scene);
	void render(Scene *scene);
};

