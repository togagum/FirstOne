#include <iostream>
#include "Queue.h"

void initQueue(Queue* q, unsigned int size)
{
	q->_elements = (int*)calloc(sizeof(int), size);
	q->_count = 0;
	q->_maxSize = size;
}
void cleanQueue(Queue* q)
{
	q->_count = 0;
}
void enqueue(Queue* q, unsigned int newValue)
{
	if (q->_count < q->_maxSize)
	{
		q->_elements[q->_count] = newValue;
		q->_count++;
	}
}
int dequeue(Queue* q) // return element in top of queue, or -1 if empty
{
	int topE = q->_elements[0];
	if (q->_count > 0)
	{
		for (int i = 0; i < q->_maxSize - 1; i++)
		{
			q->_elements[i] = q->_elements[i + 1];
		}
		q->_count--;
		return topE;
	}
	return -1;
}

bool isEmpty(Queue* s)
{
	return s->_count == 0;
}
bool isFull(Queue* s)
{
	return s->_count == s->_maxSize;
}

void printQrqbruh(Queue* q)
{
	for (int i = 0; i < q->_count; i++)
	{
		printf("%d, ", q->_elements[i]);
	}
	printf("\n");
}

void printnumrqbruh(int num)
{
	printf("\n%d\n", num);
}