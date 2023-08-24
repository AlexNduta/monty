#include "monty.h"
/**
 * _mul - multiply two top nodes
 * @h: topmost ite on the list
 * @line_number: line of command
 */
void _mul(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n *= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

