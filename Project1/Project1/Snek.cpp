#include "BigHead.h"

class Snake
{
	float gridSize;
	int snakeSize;
	
	Food food;
	public:
	bool collided();
	void move(Direction);
	bool hasWon();
	void grow();
	int getScore();
	void setDirection(vector goes here);
}