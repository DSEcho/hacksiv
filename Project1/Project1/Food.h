#pragma once
class Food
{
private:
	//This stores the location of the food object
	float pos[3];

	const int gridSize;
public:
	/*
	This method will be used spawn a food in the map  dimensions
	without overlapping with other food, or the sneks
	*/
	void spawn();

	/*
	This returns the postion, which will be whole numbers,
	but the function that calls it wants floats, so floats.
	*/
	float getPos();
};