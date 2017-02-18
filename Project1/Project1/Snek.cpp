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
bool Snek<ItemType>::collide()
{	
	Node<ItemType>* lastptr = traverse();
	Node<ItemType>* curPtr = headptr;
	curPtr = curPtr->getNext();
	bool hit = false;

	if (x >= gridSize || y >= gridSize || z >= gridSize || x < 0 || y < 0 || z < 0)

	{
		hit = true; //hit wall
	}
	for (int i = 0; i < 3; i++)
	{
		if ((food.getPos())[i] == *lastptr[i])
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


template <class ItemType>
void Snek<ItemType>::append(int *pos)
{//LITERALLY ADD A TAIL THING
	Node<ItemType>* lastptr = traverse();
	lastptr->getnext() = new Node<ItemType>(*pos, nullptr);
	currentlength++;
}
template <class ItemType>
void Snek<ItemType>::removehead()
{
	Node<ItemType>* newhead = headptr;
	newhead = headptr->getNext();
	currentlength--;
}
template <class ItemType>
void Snek<ItemType>::move(int *pos)
{
	append(pos);
	if (!collidefood())
	{
		removehead();
	}

}


/*
if size some number we want and win

*/
/*template <class ItemType>
bool Snek<ItemType>::hasWon()
{

}


/*
will just create a new object at end.

will be confusing, because we will be adding and subtracting 
snek body parts.

*/
template <class ItemType>
bool Snek<ItemType>::collidefood()
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
/*template <class ItemType>
int Snek<ItemType>::getScore()
{

}
template <class ItemType>
int Snek<ItemType>::spawnfood()
{

}
*/