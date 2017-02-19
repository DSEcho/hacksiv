//  Adapted from Frank M. Carrano and Timothy M. Henry.

/** @file Node.h  */
#ifndef NODE_H
#define NODE_H


class Node
{
private:
   int *item; // A data item
   Node* next; // Pointer to next node
   
public:
   Node();
   Node(int*& anItem);
   Node(int*& anItem, Node* nextNodePtr);
   void setItem( int *&anItem);
   void setNext(Node* nextNodePtr);
   int *getItem() ;
   Node* getNext() ;
   bool hasNext();
   //Node& operator=(const Node &rhs);
}; // end Node

#endif
