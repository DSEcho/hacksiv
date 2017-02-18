#include "BigHead.h"
#include "Snek.h"
#include <iostream>
using namespace std;


/*
To be called after we move.
returns true if collides with wall, self, and food
*/
template <class ItemType>
Node<ItemType>* Snek<ItemType>::traverse()
{
	Node<ItemType> *partyPtr = headptr;
	Node<ItemType> * lastptr;
	for (partyPtr; partyPtr != nullptr && !hit; partyPtr = partyPtr->getNext())
	{
		if (partyPtr->getNext() == nullptr)
		{
			lastptr = partyPtr;
		}
	}
	return lastptr;
}
template <class ItemType>
bool Snek::collide()
{	
	Node<ItemType>* lastptr = traverse();
	Node<ItemType>* curPtr = headptr;
	curPtr = curPtr->getNext();
	bool hit = false;

	if (x >= gridSize || y >= gridSize || z >= gridSize || x < 0 || y < 0 || z < 0)

	{
		hit = true;//hit wall
	}
	for (int i = 0; i < 3; i++)
	{
		if (food.getPos()[i] == *lastptr[i])
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

			if (*curPtr[i] == *lastptr[i])
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
void Snek::append(Direction)
{

}
template <class ItemType>
void Snek::removehead(Direction)
{

}
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
	int size = getscore();
	return bool big = (size >= 25000);
	/*
	if (big)
		cout << "Lmao you won yo but like let's speed up. lvl up!!!\n";
		*/

}


/*
will just create a new object at end.

will be confusing, because we will be adding and subtracting 
snek body parts.

*/
template <class ItemType>
bool Snek::collidefood()
{
	Node<ItemType>* lastptr = traverse();
	int *foodpos = food.getpos();
	for (int i = 0; i < 3; i++)
	{
		if (foodpos[i] == *lastptr[i])
		{
			countOfXYZMatch++;
		}
	}
	return countOfXYZMatch == 3;
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