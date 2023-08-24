#include "monty.h"

/**
*pint - print the head node of our stack
*@head: head node
*@line_number: head node
void pint(stack_t **head, unsigned int line_number)
{
if (head == NULL || *head == NULL)
{
printf("L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
*/

/**
 * pint - print top node in stack
 * @h: head of list
 * @line_number: bytecode line number
 */
void pint(stack_t **h, unsigned int line_number)
{
	if (!h || !*h)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);

}

