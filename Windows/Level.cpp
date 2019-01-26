#include "Level.hpp"

//Level---------------------------------------------------------

Level::Level() : Layer("level")
{
	stages.push_back(new Stage("stage1", "C:\\Users\\CatBro\\Code Project\\Projects\\Games\\C++\\Snake\\Windows\\stage1.txt"));
	stages.push_back(new Stage("stage2", "C:\\Users\\CatBro\\Code Project\\Projects\\Games\\C++\\Snake\\Windows\\stage2.txt"));

	Level::addNode(stages[0]);
}

void Level::setStage(int num)
{
	if(num < stages.size())
	Level::addNode(stages[num]);
}

//Stage---------------------------------------------------------

Stage::Stage(string id,string filename) : Node(id)
{
	ifstream file;
	file.open(filename);
	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		getline(file, stage[i]);
	}
	file.close();
}

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