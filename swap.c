#include "monty.h"
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *second_top;

	if (stack_len(*stack) < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second_top = top->next;

	top->next = second_top->next;
	second_top->next = top;

	second_top->prev = top->prev;
	top->prev = second_top;

	*stack = second_top;
}
