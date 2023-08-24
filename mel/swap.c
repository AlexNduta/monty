#include "monty.h"
/**
 * swap - rearranges the top two elements of the stack
 * effectively swapping their positions
 * @h: double pointer to a stack
 * @line_number: unsigned integer number
 */
void swap(stack_t **h, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*h)->next;
	if (tmp->next != NULL)
	{
		(*h)->next = tmp->next;
		(*h)->next->prev = *h;

	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *h;
	(*h) = tmp;
}
