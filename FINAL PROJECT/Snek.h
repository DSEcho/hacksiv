#ifndef SNEK_H
#define SNEK_H

#include <iostream>
#include <cstddef>
using namespace std;

#include "Node.h"
#include "Food.h"

class Snek {
private:
	Node* boopptr;
	int currentlength;
	Food food;
	int gridsize = 38;
	int snakeSize;
	Node* headptr;
	bool lost = false;
public:
	
	Snek();
	bool collide( int *pos);
	//bool hasWon();
	void move(int *pos);
	bool collidefood();
	void spawnfood();
	void append(int *pos);
	void removehead();
	Node* traverse();
	Food getFood();
	Node* getHead();
	bool lose(int *pos);
	bool hasLost();
	int getscore();
	void saveScore();
};
#endif