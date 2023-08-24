#include "monty.h"

/**
*pint - print the head node of our stack
*@head: head node
*@line_number: head node
*/
void pint(stack_t **head, unsigned int line_number)
{
if (head == NULL || *head == NULL)
{
printf("L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
