#include "monty.h"
/**
 * _mod - remainder when top is divided from botom
 * @h: topmost item on the list
 * @line_number: line of command
 */
void _mod(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0 || (*h)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*h)->next->n %= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

