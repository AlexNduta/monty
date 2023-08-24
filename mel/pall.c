#include "monty.h"
/**
 * pall - print all stack members
 * @h: topmost item on the stack
 * @line_number: bytecode line number
 */
void pall(stack_t **stack, unsigned int line)
{
stack_t *node = *stack;

if (node == NULL)
return;

(void) line;

while (node != NULL)
{
printf("%d\n", node->n);
node = node->next;
}
}


