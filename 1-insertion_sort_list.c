#include "sort.h"


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
 * insertion_sort - sorts an d-linked list using an insertion sort
 * @list: a ptr to the list head node
 * Return: is void
 */

void insertion_sort_list(listint_t **list)
{
	int swap = 0;
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	while (current != NULL)				/* move through list one element at a time */
	{
		if (current->next != NULL)
		{
			if (current->n > (current->next)->n)
			{
				swap_nodes(current, current->next);
				swap = 1;
				print_list(*list);
				temp = current->prev;
				while (temp != NULL)
				{
					if (temp->prev == NULL)
						break;
					if (temp->n < (temp->prev)->n)
					{
						swap_nodes(temp->prev, temp);
						if (temp->prev == NULL)
							*list = temp;
						print_list(*list);
					}
					else
						break;
				}
			}
		}
		if (swap == 0)
			current = current->next;
		else
			swap = 0;
	}
}
