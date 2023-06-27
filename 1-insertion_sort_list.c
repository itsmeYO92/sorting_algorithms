#include "sort.h"

/**
 * insertion_sort_list - sort a list using insert sort algorithm
 * @list: list to sort
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back, *tmp;

	if (!list || !(*list))
		return;
	if ((*list)->next == NULL)
		return;

	current  = (*list)->next;
	while (current)
	{
		back = current->prev;
		tmp = current->next;

		while (back && current->n < back->n)
		{
			swap_nodes(list, &back, current);
			print_list(*list);
		}
		current = tmp;
	}
}

/**
* swap_nodes - Swap two adjusent nodes in list
* @head:    A pointer to the head of the double-linked list
* @nodeP1:  A pointer to the first node to swap
* @nodeP2:  A pointer to the second node to swap
*/
void swap_nodes(listint_t **head, listint_t **nodeP1, listint_t *nodeP2)
{
	(*nodeP1)->next = nodeP2->next;
	if (nodeP2->next != NULL)
		nodeP2->next->prev = *nodeP1;
	nodeP2->prev = (*nodeP1)->prev;
	nodeP2->next = *nodeP1;
	if ((*nodeP1)->prev != NULL)
		(*nodeP1)->prev->next = nodeP2;
	else
		*head = nodeP2;
	(*nodeP1)->prev = nodeP2;
	*nodeP1 = nodeP2->prev;
}
