#include "monty.h"

/**
 * push - adds node to the start of dlinkedlist
 * @stack: head of linked list which is a double pointer to
 * a stack
 * @line: unsigned integer representing the line number
 * @token: string
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
