#include "monty.h"
/**
 * rotr - implements the rotate right operation
 * on a stack.
 * @h: double pointer node
 * @line_number: unsigned integer value
 */
void rotr(stack_t **h, unsigned int line_number)
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
tmp->prev->next = NULL;
tmp->prev = NULL;
(*h) = (*h)->prev;
}
}
