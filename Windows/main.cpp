#include "Level.hpp"
#include "Snake.hpp"

#include<cstdio>
#include<conio.h>

int main()
{
	//Scenes

	Scene gameManager(GAME_WIDTH,GAME_HEIGHT);

	//Layer
	Level* level = new Level;

	//Nodes
	Snake* snake = new Snake;
	Food* food = new Food;

	level->addNode(food);
	level->addNode(snake);
	gameManager.addLayer(level);
	gameManager.render();
	gameManager.gameRenderer.refresh();

	char key='\0';

	while (1)
	{
		Sleep(100);
		if(_kbhit())
		key = _getch();
		snake->setDirection(key);
		snake->moveSnake(&gameManager,food);
		if (snake->score == 3)
		{
			level->removeNode("stage1");
			level->setStage(1);
		}
		gameManager.gameRenderer.clear();
		gameManager.render();
		gameManager.gameRenderer.refresh();
	}

	return 0;
}