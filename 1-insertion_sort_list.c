#include "sort.h"

/**
 * insertion_sort_list - sorts an dll of integers in ascending order
 * @list: the dll to sort
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *next_node, *sorted;

	if (!list || !*list || !(*list)->next)
		return;
	current_node = (*list)->next;
	sorted = NULL;
	while (current_node)
	{
		next_node = current_node->next;
		if (!sorted || current_node->n < sorted->n)
		{
			current_node->prev = NULL;
			current_node->next = sorted;
			if (sorted)
				sorted->prev = current_node;
			sorted = current_node;
		}
		else
		{
			listint_t *temp = sorted;

			while(temp->next && temp->next->n < current_node->n)
				temp = temp->next = current_node;
		}
		while((*list)->prev)
			*list = (*list)->prev;
		print_list(*list);
		current_node = next_node;
	}
}
