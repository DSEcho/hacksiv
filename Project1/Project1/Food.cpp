#include "Food.h"

/*
This method will be used spawn a food in the map  dimensions
without overlapping with other food, or the sneks
*/
void Food::spawn()
{

}

/*
This returns the postion, which will be whole numbers,
but the function that calls it wants floats, so floats.
*/
float *Food::getPos()
{
	return pos;
}