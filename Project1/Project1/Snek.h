#ifndef SNEK_H
#define SNEK_H

#include <iostream>
#include <cstddef>
using namespace std;

#include "Node.h"
#include "Food.h"

template <class ItemType>
class Snek {
private:
	Node<ItemType>* = headptr;
	int currentlength;
	Food food;
	int gridsize = 50;
	int snakeSize;
public:
	bool collide();
	bool hasWon();
	void move(int);
	bool collidefood();
	void getScore();
	void spawnfood();
	void append();
	void removehead();
	Node<ItemType>* Snek<ItemType>::traverse();
};
#endif