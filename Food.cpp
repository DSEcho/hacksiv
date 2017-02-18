#include "BigHead.h"

class Food
{
	float *pos[3];
	const gridSize;
	public:
	void spawn();
	float getPos();
};

Food()
{
	pos[0]= rand() % gridSize;
	pos[1]= rand() % gridSize;
	pos[2]= rand() % gridSize;
}

float  * getPosition()
{
	return pos;
}