#include "BigHead.h"
#include "Snek.h"
#include <iostream>
using namespace std;


/*
To be called after we move.
returns true if collides with wall, self, and food
*/
template <class ItemType>
bool Snek::collide()
{
	Node<ItemType> *curPtr = headptr;

	curPtr = curPtr->getNext();
	bool hit = false;

<<<<<<< HEAD

	if (x >= 50 || y >= 50 || z >= 50 || x < 0 || y < 0 || z < 0)
=======
	if (x >= gridSize || y >= gridSize || z >= gridSize || x < 0 || y < 0 || z < 0)
>>>>>>> origin/master
	{
		hit = true;//hit wall
	}
	for (int i = 0; i < 3; i++)
	{
		if (food.getPos()[i] == *headPtr[i])
		{
			hit = true;
		}
	}
	
	// hit self.
	for (curPtr; curPtr != nullptr && !hit; curPtr = curPtr->getNext())
	{// ranges from 0 - 2
		// 0 is x
		// 1 is y
		// 2 is z
		int countOfXYZMatch = 0;
		for (int i = 0; i < 3; i++)
		{

			if (*curPtr[i] == *headptr[i])
			{
				countOfXYZMatch++;
			}
		}
		if (countOfXYZMatch == 3)
		{
			hit = true;
		}
		countOfXYZMatch = 0;
		

	}

	return hit;
}



/*
we will be controlling all the positions of the linked list

alex is writing something that will traverse a link list.


eventually will call logic on chalk board
*/
template <class ItemType>
void Snek::move(Direction)
{

}


/*
if size some number we want and win

*/
template <class ItemType>
bool Snek::hasWon()
{

}


/*
will just create a new object at end.

will be confusing, because we will be adding and subtracting 
snek body parts.

*/
template <class ItemType>
void Snek::grow()
{


}

/*
returns the current size minus default size
*/
template <class ItemType>
int Snek::getScore()
{

}
template <class ItemType>
int Snek::spawnfood()
{

}