#include <stddef.h>
#include "sort.h"

/**
 * count_list_length - returns the length of a linked list
 * @list: a ptr to the list
 * Return: the list length
 */

int count_list_length(listint_t *list)
{
	int length = 0;

	while (list != NULL)
	{
		list = list->next;
		length++;
	}
	return (length);
}

/**
 * swap_nodes - swaps two nodes in a linked list
 * @current: the first node
 * @next: the other node
 * Return: is void
 */

void swap_nodes(listint_t *current, listint_t *next)
{
	if (current->prev != NULL)
		(current->prev)->next = next;
	next->prev = current->prev;
	current->prev = next;
	current->next = next->next;
	next->next = current;
	if (current->next != NULL)
		(current->next)->prev = current;
}

/**
 * insertion_sort_list - sorts an d-linked list using an insertion sort
 * @list: a ptr to the list head node
 * Return: is void
 */

void insertion_sort_list(listint_t **list)
{
	int swap = 0, count = 0;
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	count = count_list_length(*list);
	if (count < 2)
		return;

	current = *list;
	while (current != NULL)
	{
		swap = 0;
		if (current->next != NULL)
		{
			if (current->n > (current->next)->n)
			{
				temp = current->next;
				swap_nodes(current, current->next);
				swap = 1;
				print_list(*list);
				if (temp->prev == NULL)
					*list = temp;
				while (temp != NULL && temp->prev != NULL)
				{
					if ((temp->prev)->n < temp->n)
						break;
					swap_nodes(temp->prev, temp);
					if (temp->prev == NULL)
						*list = temp;
					print_list(*list);
				}
			}
		}
		if (swap == 0)
			current = current->next;
	}
}
