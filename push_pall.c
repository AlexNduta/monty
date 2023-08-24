#include "monty.h"

/**
 * push - adds a new node with a given integer value to the top
 * of the stack, effectively pushing a new element onto the
 * stack.
 * @stack: double pointer to a stack
 * @line: unsigned integer representing the line number
 * @token: a string token representing argument passed
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
*/



/**
 * is_number - iterates each character of string to check of isdigit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_number(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}
/**
 * push - adds node to the start of dlinkedlist
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * @n: integer
 */
void push(stack_t **h, unsigned int line_number, const char *n)
{
	if (!h)
		return;
	if (is_number(n) == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(h, atoi(n)) == -1)
		{
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall - iterates through the stack and prints the values
 * of each node
 * @stack: double pointer to a stack
 * @line: unsigned integer representing the line number
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
}*/

#include "monty.h"
/**
 * pall - print all nodes in stack
 * @h: head of list
 * @line_number: bytecode line number
 */
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!h || !*h)
		return;

	(void) line_number;
	tmp = *h;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
