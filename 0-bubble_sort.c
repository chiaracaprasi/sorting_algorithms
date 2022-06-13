#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap - swap two int pointers
 * @xp: int to swap
 * @yp: int to swap
 * Return: void
 */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * bubble_sort - sorts array of integers in ascending order using Bubble sort
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	
	if (array == NULL || size < 2)
		return;
	
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
		print_array(array, size);
	}
}
