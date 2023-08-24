#include "monty.h"
/**
* pstr - Display top stack vaue as letters if they'r valid, non zero
* and within ASCII range
* @h: topmost item on the list
* @line_number: bytecode line number
*/
void pstr(stack_t **h, unsigned int line_number)
{
stack_t *tmp;

if (!h || !*h)
{
printf("L%u: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
tmp = *h;
while ((tmp != NULL) && (tmp->n != 0) &&
(tmp->n >= 0) && (tmp->n <= 127))
{
printf("%c", (tmp)->n);
tmp = tmp->next;
}
printf("\n");
}

