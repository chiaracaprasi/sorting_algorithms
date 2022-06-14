#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


/**
 * top_down_merge- top down merges subarrays
 * @array: array given
 * @copy: pointer to copy of arrat
 * @left: left index
 * @mid: middle index
 * @right: right index
 * Return: void
 */

void top_down_merge(int *copy, int *array, int left, int mid, int right)
{
	int i = left, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right] ");
	print_array(array + mid, right - mid);

	for (k = left; k < right; k++)
	{
		if (i < mid && (j >= right || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i++;
		}
		else
		{
			copy[k] = array[j];
			j++;
		}
	}
	printf("[Done]: ");

	for (i = left; i < right; i++)
		array[i] = copy[i];

	print_array(copy + left, right - left);
}

/**
 * merge_recursive - swap two int pointers
 * @array: array given
 * @copy_arr: pointer to copy of arrat
 * @left: left index
 * @right: right index
 * Return: void
 */

void merge_recursive(int *array, int *copy_arr, int left, int right)
{
	int middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		merge_recursive(array, copy_arr, left, middle);
		merge_recursive(array, copy_arr, middle, right);
		top_down_merge(copy_arr, array, left, middle, right);
	}
}

/**
 * merge_sort - sorts array of integers in ascending order using Bubble sort
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *copy_arr;

	if (array == NULL || size < 2)
		return;

	copy_arr = malloc(sizeof(int) * size);
	if (copy_arr == NULL)
		return;

	merge_recursive(array, copy_arr, 0, size);

	free(copy_arr);
}
