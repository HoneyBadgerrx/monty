#include "l.h"
/**
 * free_stack_t - frees dlist
 * @head: pointer to head
 * Return: nothing
 */
void free_stack_t(stack_t *head)
{
	stack_t *p;

	if (head == NULL)
		return;

	while (head)
	{
		p = head->next;
		free(head);
		head = p;
	}
}
