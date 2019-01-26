#include "Level.hpp"
#include<cassert>

//Level---------------------------------------------------------

Level::Level() : Layer("level")
{
	stage = new Stage;
	Level::addNode(stage);
	loadStage("Stages\\stage1.txt");
}

void Level::loadStage(string filename)
{
	ifstream file;
	file.open(filename);
	assert(file);
	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		getline(file, stage->stage[i]);
	}
	file.close();
}

//Stage---------------------------------------------------------

Stage::Stage() : Node("stage"){}

Stage::~Stage()
{
	delete[] stage;
}

void Stage::render(Scene * scene)
{
	for (int i = 0; i <GAME_HEIGHT; i++)
	{
		scene->gameRenderer.mvprintW(0,i,stage[i]);
	}
}

//Food--------------------------------------------------------------

Food::Food() :Node("food")
{
	x = 0;
	y = 0;
}

void Food::addFood(Scene* scene)
{
	x = rand() % GAME_WIDTH;
	y = rand() % GAME_HEIGHT;
	while ((scene->gameRenderer.moveXY(x, y) && scene->gameRenderer.readCh() != ' '))
	{
		x = rand() % GAME_WIDTH;
		y = rand() % GAME_HEIGHT;
	}
}

void Food::render(Scene* scene)
{
	    if (x == 0 && y == 0)
		addFood(scene);

		scene->gameRenderer.mvprintCh(x, y, FOOD_CHAR);
}