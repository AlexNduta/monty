#include "monty.h"
/**
 * add_end_node - adds new node to the end
 * of the stack.
 * @stack: pointer to the stack
 * @n: integer value
 * Return: 0 Always on success, -1 on failure
 */
int add_end_node(stack_t **stack, int n)
{
stack_t *new = NULL;

new = malloc(sizeof(stack_t));
if (new == NULL)
{
printf("Error: malloc failed");
return (-1);
}

new->n = n;
new->next = NULL;

if (*stack == NULL)
{
new->prev = NULL;
*stack = new;
}
else
{
new->prev = *stack;
(*stack)->next = new;
*stack = new;
}

return (0);
}

