#include "monty.h"
/**
 * digimon - digit check
 * @arg: digit to be checked
 * Return: if digit or not
 */
int digimon(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * kabir - kabirus
 * @str: string
 * @opstr: opstr
 * @factor: factors
 * Return: void
 */
int kabir(char *str, char *opstr)
{
	int i = 0;

	opstr = strtok(str, "\n\t\r ");
	if (!opstr)
		return (2);
	for (i = 0; ops[i].opcode; ++i)
	{
		if (strcmp(opstr, ops[i].opcode) == 0)
			return (i);
	}
	return (-1);
}
/**
 * push - pushes
 * @head: head
 * @n: n
 * Return: boid
 */
void push(stack_t **head, unsigned int n)
{
	stack_t *p;
	char *arg;
	int q;

	arg = strtok(NULL, "\n\r\t ");
	if (!arg || digimon(arg))
	{
		fprintf(stdout, "L%u: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}
	q = atoi(arg);
	p = malloc(sizeof(stack_t));
	if (p == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		while (*head)
		{
			p = (*head)->next;
			free(*head);
			*head = p;
		}
		exit(EXIT_FAILURE);
	}
	p->n = q;
	if (*head)
		(*head)->prev = p;
	p->next = *head;
	p->prev = NULL;
	*head = p;
}
/**
 * pall - print all
 * @head: head
 * @n: n
 * Return: void
 */
void pall(stack_t **head, unsigned int n)
{
	stack_t *p = *head;

	(void)n;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
void nop(stack_t **head, unsigned int n)
{
	(void)n;
	(void)head;
}
