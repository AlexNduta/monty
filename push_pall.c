#include "monty.h"

void push(stack_t **stack, unsigned int line, char *token)
{
int value;

if (token == NULL)
{
printf("L%d: usage: push integer\n", line);
exit(EXIT_FAILURE);
}

value = atoi(token);
add_end_node(stack, value);
}

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
