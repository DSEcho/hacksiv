#include "Snek.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;




Snek::Snek() : currentlength(1)
{
	headptr = new Node();
	int* item = new int[3]{2, 2, 2};
	headptr->setItem(item);
	
	boopptr = new Node();
	int* itemBoop = new int[3]{ 1, 2, 2 };


	headptr->setNext(boopptr);
	boopptr->setItem(itemBoop);
	
	srand((unsigned int) time(NULL));
	spawnfood();
}

/*
To be called after we move.
returns true if collides with wall, self, and food
*/


Node* Snek::traverse()
{
	Node * lastptr = headptr;

	while (lastptr->hasNext()) {
		lastptr = lastptr->getNext();
	}

	return lastptr;
}


bool Snek::collide(int *pos)
{	
	Node* lastptr = traverse();
	Node* curPtr = headptr;
	curPtr = curPtr->getNext();
	bool hit = false;
	int grid_size = 38;
	if (pos[0] >= grid_size || pos[1] >= grid_size || pos[2] >= grid_size || pos[0] < 0 || pos[1] < 0 || pos[2] < 0)
	{
	
		hit = true;
	}
	
	// hit self.
	/**/
	for (curPtr; curPtr != nullptr && !hit && curPtr != lastptr; curPtr = curPtr->getNext())
	{
		// ranges from 0 - 2
		// 0 is x
		// 1 is y
		// 2 is z
		int countOfXYZMatch = 0;
		for (int i = 0; i < 3; i++) //che
		{
			
			if (curPtr->getItem()[i] == lastptr->getItem()[i] )
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


void Snek::append(int *pos)
{
	//LITERALLY ADD A TAIL THING // new node
	Node* lastptr = traverse();
	Node* lastnode = new Node(pos);
	lastptr->setNext(lastnode);
	//lastnode->setNext(nullptr);
	currentlength++;
}


void Snek::removehead()
{
	Node*& newhead = headptr;
	newhead = headptr->getNext();
	currentlength--;
}


void Snek::move(int *pos)
{
	
	append(pos);
	if (!collidefood())
	{
		removehead();

		if (lose(pos)) {
			this->lost = true;
		}
	}
	
	else 
	{	
	int i = 0;
	spawnfood();
		while (i < 3)
		{
		append(pos);
		i++;
		}
	}

}


/*
if size some number we want and win

*/

int Snek::getscore()
{
	return currentlength;
}


/*
will just create a new object at end.

will be confusing, because we will be adding and subtracting 
snek body parts.

		{
			countOfXYZMatch++;
		}
*/

bool Snek::collidefood()
{
	int countofXYZMatch = 0;
	Node* lastptr = traverse();
	int *foodpos = food.getPos();
	for (int i = 0; i < 3; i++)
	{
		if (foodpos[i] == lastptr->getItem()[i]) {
			countofXYZMatch++;
		}
		else {
			break;
		}
	}
	return countofXYZMatch == 3;
}

/*
returns the current size minus default size
*/

bool Snek::lose(int *pos)
{
	if (collide(pos) && !collidefood())
	{
		return true;
	}
	return false;
}

void Snek::spawnfood()
{
	
	int position[] = { 0,0,0 };

	bool foodOverlap = true;

	while (foodOverlap == true)
	{
		for (int index = 0; index < 3; index++)
		{
			position[index] = (rand() % 38);
		}

		for (Node* curPtr = headptr; curPtr != nullptr && foodOverlap; curPtr = curPtr->getNext())
		{
			
			// ranges from 0 - 2
			// 0 is x
			// 1 is y
			// 2 is z
			int countOfXYZMatch = 0;
			for (int i = 0; i < 3; i++)
			{

				if (curPtr->getItem()[i] == position[i])
				{
					countOfXYZMatch++;
				}
			}


			if (countOfXYZMatch == 3)
			{
				foodOverlap = true;
			}
			else
			{
				foodOverlap = false;
			}
				
			countOfXYZMatch = 0;


		}

		food.setPos(position);
	}
}
	

Food Snek::getFood() {
	return food;
}

Node * Snek::getHead()
{
	return headptr;
}

bool Snek::hasLost() {
	return this->lost;
}

void Snek::saveScore()
{
	
	ofstream out("high_score.txt");

	out << "Your score was: " << getscore() << "\n";
	out.close();
}
