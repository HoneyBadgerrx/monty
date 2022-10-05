#include "monty.h"

/**
 * kabir - kabirus
 * @str: string
 * @opstr: opstr
 * @factor: factors
 * Return: void
 */
int kabir(char *str, char opstr[], int *factor)
{
	int i = 0, q, flag = 0;
	char *k;

	for (i = 0; str[i] == ' '; ++i)
		;
	if (str[i] == '\n' || !str[i])
		return (2);
	for (i = 0; str[i] != '\n'; ++i)
	{
		for (;str[i] == ' '; ++i)
			;
		k = malloc(300);
		for (q = 0; str[i] != ' ' && str[i] != '\n' && str[i]; ++q, ++i)
			k[q] = str[i];
		k[q] = '\0';
		if (flag == 1)
		{
			*factor = atoi(k);
			free(k);
			break;
		}
		strcpy(opstr, k);
		free(k);
		flag = 1;
	}
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
	stack_t *p = malloc(sizeof(stack_t));

	if (p == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		while (*head)
		{
			p = (*head)->next;
			free(*head);
			*head = p;
		}
		exit(EXIT_FAILURE);
	}
	p->n = n;
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
