#include "Level.hpp"
#include "Snake.hpp"

#include<cstdio>
#include<conio.h>
#include<ctime>

int main()
{
	srand(time(nullptr));
	//Scenes
	Scene gameManager(GAME_WIDTH,GAME_HEIGHT+1);

	//HEADING FLASH
	gameManager.gameRenderer.mvprintW(GAME_WIDTH/2-5,GAME_HEIGHT/2, "SNAKE GAME");
	gameManager.render();
	gameManager.gameRenderer.refresh();
	Sleep(1500);
	gameManager.gameRenderer.clear();

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

	string status = "Stage:                                                                                      Score:  ";
	for(int i=7;i<92;i++)
		status[i]=176;
	
	char key='\0';
	int stage = 1;
	while (1)
	{
		Sleep(100);

		if(_kbhit())
		key = _getch();
		snake->setDirection(key);
		snake->moveSnake(&gameManager,food);

		gameManager.gameRenderer.clear();
		gameManager.render();
		
		//STATUS BAR
		for(int i=0;i<(85*(double(snake->score % 10)/10.0));i++)
		 status[i+7]=219;
		gameManager.gameRenderer.mvprintW(0,GAME_HEIGHT,status);
		gameManager.gameRenderer.mvprintW(6,GAME_HEIGHT,to_string(stage));
		gameManager.gameRenderer.mvprintW(98,GAME_HEIGHT,to_string(snake->score));
		
		gameManager.gameRenderer.refresh();
		
		if (snake->score == 30)
			break;
		
		//STAGE CHANGE
		if (snake->bodyLength == 12)
		{
			if (stage == 3)
				stage = 0;
			stage++;

			snake->reset();
			
		    for(int i=7;i<92;i++)
		        status[i]=176;

			gameManager.removeLayer("level");
			gameManager.gameRenderer.clear();
			gameManager.gameRenderer.mvprintW(GAME_WIDTH / 2 - 3, GAME_HEIGHT / 2, "STAGE"+std::to_string(stage));
			gameManager.gameRenderer.refresh();
			Sleep(1500);
			gameManager.gameRenderer.clear();
			level->loadStage("Stages\\stage"+std::to_string(stage)+".txt");
			gameManager.addLayer(level);
			gameManager.render();
			food->addFood(&gameManager);
		}
	}

	//WIN FLASH
	gameManager.removeLayer("level");
	gameManager.gameRenderer.clear();
	gameManager.gameRenderer.mvprintW(GAME_WIDTH / 2 - 4, GAME_HEIGHT / 2, "YOU WIN");
	gameManager.gameRenderer.mvprintW(GAME_WIDTH / 2 - 4, GAME_HEIGHT / 2 + 1, "SCORE: " + std::to_string(snake->score));
	gameManager.render();
	gameManager.gameRenderer.refresh();
	Sleep(2500);
	return 0;
}