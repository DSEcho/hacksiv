#pragma once
#include "Snek.h"
class Food
{
private:
	//This stores the location of the food object
	int pos[3];
	int gridSize[] = { 50,50,50 };
public:
	Food();
	/*
	This method will be used spawn a food in the map  dimensions
	without overlapping with other food, or the sneks
	*/
	int *setPos(int* position);
	/*
	This returns the postion, which will be whole numbers,
	but the function that calls it wants ints, so ints.
	*/
	int *getPos();
};