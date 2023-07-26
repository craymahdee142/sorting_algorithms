#include "sort.h"

/**
 *swap_nodes - swap two nodes in doubly linked list
 *@head: pointer to a the head of a doubly linked list
 *@node1: points to the first node
 *@node2: second nodes
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	/* make (node1)'s next point to the node after node2 */
	(*node1)->next = node2->next;
	if (node2->next)
		node2->next->prev = *node1;
	/* update node2 prev's to point to the next node before node 1*/
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev)
		(*node1)->prev->next = node2;
	else
		*head = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 *insertion_sort_list - sort a doubly linked list of intergers
 *			 using the indertion sort algorithm
 *@list: Pointer to the head of doubly linked list of integers
 *Description: prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insert = current->prev;
		/* find correct posi to insert the current node */
		while (insert != NULL && current->n < insert->n)
		{
			swap_nodes(list, &insert, current);
			print_list((const listint_t *)*list);
		}
	}
}
