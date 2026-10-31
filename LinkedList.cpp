#include "LinkedList.h"
#include <iostream>

void initNode(Node* n, unsigned int value)
{
	n->value = value;
	n->nextNode = nullptr;
}

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