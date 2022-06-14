#include <stdio.h>
#include <stddef.h>
#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a linked list
 * @n1: the first node
 * @n2: the next node
 * Return: is void
 */

void swap_nodes(listint_t *n1, listint_t *n2)
{
	if (n1->prev != NULL)
		(n1->prev)->next = n2;
	if (n2->next != NULL)
		(n2->next)->prev = n1;
	n2->prev = n1->prev;
	n1->prev = n2;
	n1->next = n2->next;
	n2->next = n1;
}

/**
 * cocktail_sort_list - sorts an d-linked list using a cocktail sort
 * @list: a ptr to the list head node
 * Return: is void
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;

	temp = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(temp, temp->next);
				if ((temp->prev)->prev == NULL)
					*list = temp->prev;
				print_list(*list);
				swapped = 1;
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->n < (temp->prev)->n)
			{
				swap_nodes(temp->prev, temp);
				if (temp->prev == NULL)
					*list = temp;
				print_list(*list);
				swapped = 1;
			}
			else
				temp = temp->prev;
		}
	}
}
