#include "sort.h"

/**
 * partition - divides the given array around a pivot
 * @A: the array of integers
 * @left: the left index of the array that we are partitioning
 * @right: the right most index
 * @size: size of array
 * Return: the index at which index is placed after partitioning
 */

int partition(int *A, int size, int left, int right)
{
	int i, j, temp, pivot;

	pivot = A[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (A[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				print_array(A, size);
			}
		}
		j++;
	}
	if (A[right] < A[i + 1])
	{
		A[right] = A[i + 1];
		A[i + 1] = pivot;
		print_array(A, size);
		return (i + 1);
	}
	return (right);
}

/**
 * sort_quick - a quick_sort function that recursively sorts an array of ints
 * @A: the array of ints that we are sorting
 * @left: the leftmost index to sort
 * @right: the rightmost index to sort
 * @size: size of array
 * Return: is void
 */

void sort_quick(int *A, int size, int left, int right)
{
	int p;

	if (left >= right || left < 0)
		return;
	p = partition(A, size, left, right);
	sort_quick(A, size, left, p - 1);
	sort_quick(A, size, p + 1, right);
}

/**
 * quick_sort - sorts an array using a quick sort
 * @array: the array of integers
 * @size: the size of the array
 * Return: is void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	if (size <= 0)
		return;

	sort_quick(array, size, 0, size - 1);
}
