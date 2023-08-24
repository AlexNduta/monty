#include "monty.h"
/**
 * delete_end_node - deletes node at end of list
 * @h: pointer to head of our list
 */
void delete_end_node(stack_t **h)
{
	stack_t *del = NULL;

	/* account for only one node in list */
	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else /* else delete front, and link correctly */
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}

