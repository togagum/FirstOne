#include <iostream>
#include "Utils.h"
#define ARRSIZE 10

void reverse(int* nums, unsigned int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = nums[i];
		nums[i] = nums[size - 1 - i];
		nums[size - 1 - i] = temp;
	}
}
int* reverse10()
{
	int* arr = (int*)calloc(ARRSIZE, sizeof(int));
	std::cout << "Enter 10 numbers (split by lines):" << std::endl;
	for (int i = 0; i < ARRSIZE; i++)
	{
		std::cin >> arr[i];
	}
	return arr;
}