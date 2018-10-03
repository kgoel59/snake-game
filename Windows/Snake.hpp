#ifndef _SNAKE_
#define _SNAKE_

#include "GameManager.hpp"
#include <vector>

using std::vector;
using std::pair;

class Snake:virtual public GameManager
{
	int x,y;
	int bodyLength;
	char direction;
	bool dead=false;
	vector<pair<int,int> > body;
public:
	Snake():x(20),y(10),bodyLength(2),direction('d'){
		for(int i=1;i<=bodyLength;i++)
		{
			body.push_back(pair<int,int>(x-i,y));
		}
	}
	void eat();
	void moveSnake();
	void setDirection(char);
	int  die();
	void render();
};

#endif
