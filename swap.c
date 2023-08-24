#include "monty.h"
/**
 * swap - rearranges the top two elements of
 * the stack, effectively swapping their
 * positions.
 * @stack: a parameter
 */
void swap(stack_t **stack)
{
stack_t *top = *stack;
stack_t *second_top = top->next;

if (*stack == NULL || (*stack)->next == NULL)
{
return;
}

if (second_top->next == NULL)
{
printf("Can't swap, stack too short\n");
return;
}

top->next = second_top->next;
second_top->next = top;

second_top->prev = top->prev;
top->prev = second_top;

*stack = second_top;
}

