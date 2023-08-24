#include "monty.h"

/**
*pop - deletes the head of the list
*@head: a pointer to the head of our linked list
*@line_number: the number of lines

void pop(stack_t **head, unsigned int line_number)
{
stack_t *del = *head;

if (head == NULL || (*head) == NULL)
{
printf("L%u: can't pop an empty stack\n", line_number);
free_list(head);
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
*/

/**
 * pop - removes node at front of dlinkedlist
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 */
void pop(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(h);
}

