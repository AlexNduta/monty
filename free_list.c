#include "monty.h"
/**
*free_list - frees a list with only integee data
*@head: pointer to the head of the list
*


void free_list(stack_t **head)
{
if (!head)
return;
while (*head && (*head)->next)
{
*head = (*head)->next;
free((*head)->prev);
}
free(*head);
}
*/

void free_list(stack_t **h)
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

