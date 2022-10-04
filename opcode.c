#include "l.h"

int kabir(char *str, char * opstr, int *factor)
{
	int i = 0;
	char *opstr = strtok(str, " ");
	char *factor = strtok(str, " ");

	for (i = 0; ops[i]->opcode; ++i)
	{
		if (strcmp(opstr, ops[i]->opcode) == 0)
			return (i);
	}
	return (-1);
}
stack_t *push(**head, unsigned int n)
{
	stack_t *p = malloc(sizeof(stack_t));
	if (p == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	p->n = n;
	(*head)->prev = p;
	p->next = *head;
	p->prev = NULL;
	*head = p;
	return (p);
}
stack_t *pop(**head, unsigned int n)
{

}
stack_t *pall(**head, unsigned int n)
{
	stack_t *p = *head;

	while (p != NULL)
		prinf("%d\n", p->n);
	return (p);
}
