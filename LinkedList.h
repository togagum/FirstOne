#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
	struct Node* nextNode;
	unsigned int value;
} Node;

void initNode(Node* n, unsigned int value);

Node* getLastNode(Node* n);
Node* getNodeBeforeLast(Node *n);
void printList(Node* n);
void cleanList(Node *n);
#endif LINKEDLIST_H