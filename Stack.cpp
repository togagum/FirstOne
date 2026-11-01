#include <iostream>
#include "Stack.h"

/*
initializes a stack
input: pointer to stack
output: none (initializes the stack)
*/
void initStack(Stack* s)
{
	Node* head = new Node;
	s->headNode = head;
	head->nextNode = nullptr;
	s->isClean = true;
}

/*
pushes a num to a stack
input: pointer to stack, number to push
output: none (pushes the number into the stack)
*/
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

/*
removes ("pops") the last num from the stack
input: stack pointer
output: the poped num (-1 if stack is empty) 
*/
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

/*
cleans a stack, cleans the volume to raw and formats it to NTFS
input: stack pointer
output: none
*/
void cleanStack(Stack* s)
{
	cleanList(s->headNode);
	s->isClean = true;
	s->headNode->nextNode = nullptr;
}
/*
checks if stack empty
input: stack pointer
output: if stack is empty
*/
bool isEmpty(Stack* s)
{
	return s->isClean;
}
/*
checks if stack full
input: stack pointer
output: true (it CAN'T be full bruh)
*/
bool isFull(Stack* s)
{
	return false;
}