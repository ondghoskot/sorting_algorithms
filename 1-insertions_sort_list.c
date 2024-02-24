#include "sort.h"

/**
 * insertion_sort_list - sorts an dll of integers in ascending order
 * @list: the dll to sort
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node;
	
	if (!list || !*list || !(*list)->next)
		return;
	current_node = (*list)->next;
	while (current_node)
	{
		listint_t *insert = current_node->prev;
		listint_t *next = current_node->next;
		while (insert && insert->n > current_node->n)
			insert = insert->prev;
		if (!insert)
		{
			current_node->prev->next = current_node->next;
			if (current_node->next)
				current_node->next->prev = current_node->prev;
			current_node->prev = NULL;
			current_node->next = *list;
			(*list)->prev = current_node;
			*list = current_node;
		}
		else if (insert->next != current_node)
		{
			current_node->prev->next = current_node->next;
			if (current_node->next)
				current_node->next->prev = current_node->prev;
			current_node->next = insert->next;
			insert->next->prev = current_node;
			insert->next = current_node;
			current_node->prev = insert;
		}
		current_node = next;
		print_list(*list);
	}
}
