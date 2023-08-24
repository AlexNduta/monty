#include "monty.h"
/**
*free_list - frees a list with only integee data
*@head: pointer to the head of the list
*
*/

void free_list(stack_t **head)
{
/* if the list is empty */
if (!head)
return;
while (*head && (*head)->next)
{
*head = (*head)->next;
free((*head)->prev);
}
free(*head);
}
