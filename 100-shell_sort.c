#include "sort.h"

/**
 * insertion - performs an insertion sort on a partially sorted array
 * @array: the array of ints
 * @size: the size of the array
 * Return: is void
 */

void insertion(int *array, size_t size)
{
	unsigned int i, temp_index;
	int  temp_value;

	for (i = 0; i < size; i++)
	{
		if ((i + 1) != size)
		{
			if (array[i] > array[i + 1])
			{
				temp_index = i + 1;
				while (temp_index > 0)
				{
					if (array[temp_index - 1] > array[temp_index])
					{
						temp_value = array[temp_index - 1];
						array[temp_index - 1] = array[temp_index];
						array[temp_index] = temp_value;
					}
					else
						break;
					temp_index--;
				}
			}
		}
	}
}

/**
 * shell_sort - functions that uses a shell sort to saort an array of ints
 * @array: the array
 * @size: the size of the array
 * Return: is void
 */

void shell_sort(int *array, size_t size)
{
	int temp_value, check;
	unsigned int i, j, temp_index, gap = 1;

	if (array == NULL || size == 0)
		return;
	while (gap < size)
		gap = gap * 3 + 1;
	for (gap = (gap - 1) / 3; gap > 1; gap = (gap - 1) / 3)
	{
		for (i = 0; i < gap; i++)
		{
			temp_index = i;
			for (j = i; j < size; j = j + gap)
			{
				if (array[j] < array[temp_index])        /*swap */
				{
					temp_value = array[temp_index];
					array[temp_index] = array[j];
					array[j] = temp_value;
				}
				check = temp_index - gap;
				while (check >= 0)
				{
					if (array[check] > array[temp_index])
					{
						temp_value = array[check];
						array[check] = array[temp_index];
						array[temp_index] = temp_value;
					}
					temp_index = check;
					check = check - gap;
				}
				temp_index = j;
			}
		}
		print_array(array, size);
	}
	insertion(array, size);
	print_array(array, size);
}
