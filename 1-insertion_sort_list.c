#include "sort.h"

/**
 * insertion_sort_list - sort a list using insert sort algorithm
 * @list: list to sort
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back;

	if (!list || !(*list))
		return;
	if (!(*list)->next)
		return;

	current  = (*list)->next;
	while (current)
	{
		back = current->prev;

		if (back)
		{
			while (current->n < back->n)
			{
				back->next = current->next;
				if (current->next)
					current->next->prev = back;
				back->prev = current->prev;
				back->next = current;
				if (back->prev)
					back->prev->next = current;
				else
					*list = current;
				back->prev = current;
				back = current->prev;
				print_list(*list);
				break;
			}
		}
		current = current->next;
	}
}
