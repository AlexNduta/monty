#include "monty.h"
void pop(stack_t **head, unsigned int line_number)
{
stack_t *del = *head;

if (head == NULL || (*head) == NULL)
{
printf("L%u: can't pop an empty stack\n", line_number);
free_dlist(head);
exit(EXIT_FAILURE);
}
else
{
if ((*head)->next == NULL)
{
*head = NULL;
free(head);
}
else
{
*head = (*head)->next;
(*head)->prev = NULL;
free(del);
}
}
}
