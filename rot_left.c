#include "monty.h"
/**
* rotl - implements the rotate left operation on a stack
* reordering it's elements while maintaining the order
* of insertion
* @h: double pointer to a stack
* @line_number: unsigned integer value
*/
void rotl(stack_t **h, unsigned int line_number)
{
stack_t *tmp;

(void) line_number;

if ((*h)->next != NULL)
{
tmp = *h;
while (tmp->next != NULL)
tmp = tmp->next;
(*h)->prev = tmp;
tmp->next = *h;
(*h)->next->prev = NULL;
*h = (*h)->next;
tmp->next->next = NULL;
}
}
