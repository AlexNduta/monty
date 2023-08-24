#include "monty.h"

/**
*pop - deletes the head of the list
*@head: a pointer to the head of our linked list
*@line_number: the number of lines
 */

void pop(stack_t **head, unsigned int line_number)
{
stack_t *del = *head;

/*if the list is empty */
if (head == NULL || (*head) == NULL)
{
printf("L%u: can't pop an empty stack\n", line_number);
free_list(head);
exit(EXIT_FAILURE);
}
else
{
if ((*head)->next == NULL) /* if it is  the only item */
{
*head = NULL;
free(head); /* delete the node */
}
else
{
*head = (*head)->next; /*point head to the next pointer */
(*head)->prev = NULL; /* cut previous link */
free(del); /* delete the node */
}
}
}


