#include "sort.h"

/**
 * siftDown - fixes a heap
 * @array: array to sort
 * @key: size of array
 * @root: root of the heap
 * @last: last index of heap
 * Return: void
 */

void siftDown(int key, int *array, int root, int last)
{
	int bigger = 2 * root;

	while (bigger <= last)
	{
		if (bigger < last)
		{
			if (array[bigger + 1] > array[bigger])
				bigger++;
		}
		if (key >= array[bigger])
			break;

		array[root] =  array[bigger];
		root = bigger;
		bigger = 2 * root;
	}
	array[root] = key;
}

/**
 * heap_sort - sorts array of integers in ascending order using Heap sort
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	unsigned int i, j, item;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2; i >= 1; i--)
		siftDown(array[i], array, i, size);

	for (j = size; j > 1; j--)
	{
		item = array[j];
		array[j] = array[1];
		siftDown(item, array, 1, j - 1);
	}
}
