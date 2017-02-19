#include "Food.h"
#include <cstdlib>
using namespace std;

void Food::setPos(int* position)
{
	for (int i = 0; i < 3; i++)
	{
		pos[i] = position[i];
	}
}
/*
This returns the postion, which will be whole numbers,
but the function that calls it wants floats, so floats.
*/
int *Food::getPos()
{
	return pos;
}