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

public:
	bool collide();
	bool hasWon();
	void move(int);
	void grow();
};
#endif