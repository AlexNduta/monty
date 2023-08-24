#include "monty.h"
/**
 * free_dlist - frees a doubly linked list with only integers
 * @h: the topmost item on the list
 */
void free_dlist(stack_t **h)
{
	/* return if empty list */
	if (!h)
		return;

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}

