#include "monty.h"

/**
 * push - adds a new node with a given integer value to the top
 * of the stack, effectively pushing a new element onto the
 * stack.
 * @stack: double pointer to a stack
 * @line: unsigned integer representing the line number
 * @token: a string token representing argument passed
 */
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
/**
 * pall - iterates through the stack and prints the values
 * of each node
 * @stack: double pointer to a stack
 * @line: unsigned integer representing the line number
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
