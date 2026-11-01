#include <iostream>
#include "Utils.h"
#define ARRSIZE 10
/*
Reverses an array by order
input: array pointer, array size
output: none (affects the array)
*/
void reverse(int* nums, unsigned int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = nums[i];
		nums[i] = nums[size - 1 - i];
		nums[size - 1 - i] = temp;
	}
}
/*
get 10 numbers from user input and return an array with the numbers
input: none (user input)
output: created array
*/
int* reverse10()
{
	int* arr = (int*)calloc(ARRSIZE, sizeof(int));
	std::cout << "Enter 10 numbers (split by lines):" << std::endl;
	for (int i = 0; i < ARRSIZE; i++)
	{
		std::cin >> arr[i]; //input number in user input to array index
	}
	return arr;
}