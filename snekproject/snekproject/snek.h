#ifndef SNEK_H
#define SNEK_H

#include <iostream>
#include <cstddef>
using namespace std;

#include "Node.h"
#include "food.h"

template <class ItemType>
class Snek {
private:
	Node<ItemType>* = headptr;
	int currentlength;
	int direction;

public:
	bool collide();
	bool hasWon();
	void move(int);
	void grow();
};
#endif