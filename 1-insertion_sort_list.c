#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * insert - insert node in its ordered position in a doubly linked list
 * @list: list of nodes
 * @node1: node being inserted
 * @node2: node to insert infront of
 */
void insert(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node2 == *list)
	{
		/* detach node1 from it's current positon */
		node1->prev->next = node1->next;

		if (node1->next)
			node1->next->prev = node1->prev;

		/* insert at beginning of list */
		node1->next = *list;
		node1->prev = NULL;
		(*list)->prev = node1;
		*list = node1;
	}
	else
	{
		/* detach node1 from it's current positon */
		node1->prev->next = node1->next;

		if (node1->next)
			node1->next->prev = node1->prev;

		/* insert just before of node2 */
		node2->prev->next = node1;
		node1->prev = node2->prev;
		node1->next = node2;
		node2->prev = node1;
	}

	print_list(*list);
}

/**
 * insertion_sort_list - sort a doubly-linked list using the insertion sort
 * algorithm
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *curr, *node;

	current = *list;
	while (current)
	{
		curr = current;
		node = current;

		while (curr->prev && (node->n < curr->prev->n))
			curr = curr->prev;

		if (node != curr)
			insert(list, node, curr);

		current = current->next;
	}
}
