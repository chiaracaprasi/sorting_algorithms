#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * counting_sort - uses an array of ints (0 to highest number)
 *                 to count instances of each int in the range
 * @array: the array of ints to count instances of
 * @size: the size of array
 * Return: is void
 */

void counting_sort(int *array, size_t size)
{
	unsigned int largest_number = 0, count = 0, i, j;
	int *new_array;
	char *sep = "";

	if (size < 2)
		return;
	for (i = 0; i < (unsigned int)size; i++)
	{
		if ((unsigned int)array[i] > largest_number)
			largest_number = array[i];
	}
	new_array = malloc(sizeof(*new_array * (largest_number + 1)));
	if (new_array == NULL)
		return;
	for (i = 0; i <= largest_number; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((unsigned int)array[j] == i)
				count++;
		}
		new_array[i] = count;
		printf("%s", sep);
		printf("%d", new_array[i]);
		sep = ", ";
	}
	printf("\n");
	count = 0;
	j = 0;
	for (i = 0; i <= largest_number; i++)
	{
		if ((unsigned int)new_array[i] > count)
		{
			array[j] = i;
			j++;
			count++;
		}
	}
	free(new_array);
}
