//  Adapted from Frank M. Carrano and Timothy M. Henry.

/** @file Node.cpp */

#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"
#include <cstddef>


Node::Node() : next(nullptr)
{
} // end default ructor

/*Node& Node::operator=( Node &rhs)
{

	delete[] this->item;
	this->item = new int[3];
	for (int i = 0; i < 3; i++)
	{
		this->item[i] = rhs.item[i];
	}

	return *this;
}
*/
Node::Node( int*& anItem)
{
	this->item = anItem;
	this->next = nullptr;
} // end ructor


Node::Node( int*& anItem, Node* nextNodePtr)
{
	this->item = anItem;
	this->next = nextNodePtr;
} // end ructor
 

void Node::setItem( int *&anItem)
{ 
	
	item = anItem;
} // end setItem


void Node::setNext(Node* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext


int* Node::getItem() 
{
   return item;
} // end getItem


Node* Node::getNext() 
{
   return next;
} // end getNext

bool Node::hasNext()
{
	return this->next != nullptr;
}

#endif

