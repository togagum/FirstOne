#include "LinkedList.h"
#include <iostream>

/*
initialize a node
input: node location pointer, node's initialized stored value
output: none (affects node itself)
*/
void initNode(Node* n, unsigned int value)
{
	n->value = value;
	n->nextNode = nullptr;
}

/*
returns a pointer to the last node in a list of nodes
input: list's head
output: list's last node
*/
Node* getLastNode(Node *n)
{
	Node* prevN = n;
	Node* currN = n;
	if (currN->nextNode == nullptr)
	{
		return prevN;
	}
	currN = currN->nextNode;
	while (currN != nullptr)
	{
		currN = currN->nextNode;
		prevN = prevN->nextNode;
	}
	return prevN;
}

/*
returns a pointer to the node before the last node in a list of nodes
input: list's head
output: list's node before last node
*/
Node* getNodeBeforeLast(Node* n)
{
	Node* BefLastN = n;
	Node* prevN = n;
	Node* currN = n;
	if (currN->nextNode == nullptr)
	{
		return nullptr;
	}
	currN = currN->nextNode;
	if (currN->nextNode == nullptr)
	{
		return prevN;
	}
	while (currN != nullptr)
	{
		BefLastN = prevN;
		currN = currN->nextNode;
		prevN = prevN->nextNode;
	}
	return BefLastN;
}

/*
prints a list
input: list's head node
output: none (prints if printf commands uncommented)
*/
void printList(Node *n)
{
	Node* currN = n;
	while (currN != nullptr)
	{
		//printf("okay, were good, currently i am in %p and will jump to %p\n", currN, currN->nextNode);
		//printf("%d\n", currN->value);
		currN = currN->nextNode;
	}
}

/*
cleans a list by removing reach node after the head node
input: list's head node
output: none (deletes nodes)
*/
void cleanList(Node* n)
{
	Node* curr = n->nextNode;
	while (curr != nullptr)
	{
		Node* todel = curr;
		curr = curr->nextNode;
		delete(todel);
	}
}