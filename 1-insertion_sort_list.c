#include "sort.h"

/**
 * swap_nodes - Swap two_nodes in a listint_t of doubly-linked list.
 * @h: double pointer to the head_node of the doubly-linked list.
 * @n1: first_node to swap.
 * @n2: Pointer to the second_node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts the doubly_linked_list of int
 *          using the insertion_sort_algorithm.
 * @list: double pointer to the head_node of a doubly-linked_list of int.
 *
 * Description: display resulting list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *t;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = t)
	{
		t = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
