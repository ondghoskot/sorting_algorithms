#include "sort.h"

/**
 * swap_nodes - swaps a node with a previous one
 * @node: the node to swap
 * Return: nothing
 */
void swap_nodes(listint_t *node)
{
	listint_t *i, *j, *nxt;

	if(!node->prev)
		return;
	i = node->prev;
	j = i->prev;
	nxt = node->next;
	if (j)
		j->next = node;
	node->prev = j;
	node->next = i;
	i->prev = node;
	i->next = nxt;
	if (nxt)
		nxt->prev = i;
}

/**
 * insertion_sort_list - sorts an dll of integers in ascending order
 * @list: the dll to sort
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *temp;

	if (!list || !*list)
		return;
	current_node = (*list)->next;
	while (current_node)
	{
		if (current_node->prev->n > current_node->n)
		{
			temp = current_node->next;
			while (current_node->prev)
			{
				if (current_node->n < current_node->prev->n)
				{
					swap_nodes(current_node);
					while((*list)->prev)
						(*list) = (*list)->prev;
					print_list(*list);
				}
				else
					break;
			}
			current_node = temp;
		}
		else
			current_node = current_node->next;
	}
}
