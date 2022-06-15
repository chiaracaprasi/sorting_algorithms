#include "sort.h"

/**
 * siftDown - fixes a heap
 * @array: array to sort
 * @size: size of array
 * @root: root of the heap
 * @h: heap size
 * Return: void
 */

void siftDown(int *array, int size, int root, int h)
{
	int max = root, l = root * 2 + 1, r = root * 2 + 2;
	int temp;

	if (l < h && array[l] > array[max])
		max = l;

	if (r < h && array[r] > array[max])
		max = r;

	if (max != root)
	{
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		siftDown(array, size, max, h);
	}
}

/**
 * heap_sort - sorts array of integers in ascending order using Heap sort
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	unsigned int i, temp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i > 0; i--)
		siftDown(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		if (i != 0)
			print_array(array, size);
		siftDown(array, size, 0, i);
	}
}
