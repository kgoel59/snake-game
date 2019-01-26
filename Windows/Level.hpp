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
	vector<Stage*> stages;

public:

	Level();
	void setStage(int num);

};

class Stage : public Node
{
	string *stage = new string[GAME_HEIGHT]; 

public:
   
	Stage(string id,string filename);
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
