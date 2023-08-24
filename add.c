#include "monty.h"
/**
*_add - adds the head and the element below it
*@head: pointer to the head node
*@line_number: line number
*/

void _add(stack_t **head, unsigned int line_number)
{
/*if the list is empty */
if (*head == NULL || (*head)->next == NULL)
{
printf("L%u: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*head)->next->n += (*head)->n;
(*head) = (*head)->next;
free((*head)->prev);
(*head)->prev = NULL;
}



