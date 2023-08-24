#include "monty.h"
/**
 * nop - used when the monty code includes a 'nop' instruction
 * indicating that no specific operation should be performed
 * at that point.
 * @stack: double pointer to a stack
 * @line_num: an unsigned integer representing the line number
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}*/

/**
 * nop - do nothing
 * @h: head of list
 * @line_number: bytecode line number
 */
void nop(stack_t **h, unsigned int line_number)
{
	(void) h;
	(void) line_number;
}

