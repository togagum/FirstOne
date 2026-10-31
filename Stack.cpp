#include <iostream>
#include "Stack.h"

void initStack(Stack* s)
{
	Node* head = new Node;
	s->headNode = head;
	head->nextNode = nullptr;
	s->isClean = true;
}

void push(Stack* s, unsigned int element)
{
	if (s->isClean)
	{
		s->headNode->value = element;
		s->isClean = false;
		return;
	}
	Node* pushedNode = new Node;
	getLastNode(s->headNode)->nextNode = pushedNode;
	initNode(pushedNode, element);
}

int pop(Stack* s) // Return -1 if stack is empty
{
	if (s->isClean)
	{
		//printf("nothing to poop\n");
		return -1;
	}
	Node* lastNode = getLastNode(s->headNode);
	//printf("last node's value:%u\n", lastNode->value);
	int poppedElement = lastNode->value;
	if (lastNode == s->headNode)
	{
		//printf("just set clean as true\n");
		s->isClean = true;
	}
	else
	{
		Node* beforeLast = getNodeBeforeLast(s->headNode);
		//printf("value of node before last one: %u\n", beforeLast->value);
		delete(lastNode);
		beforeLast->nextNode = nullptr;
	}
	return poppedElement;
}

void cleanStack(Stack* s)
{
	cleanList(s->headNode);
	s->isClean = true;
	s->headNode->nextNode = nullptr;
}

bool isEmpty(Stack* s)
{
	return s->isClean;
}
bool isFull(Stack* s)
{
	return false;
}