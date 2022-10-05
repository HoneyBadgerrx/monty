#include "monty.h"
instruction_t ops[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};
/**
 * main - main
 * @argc: argc
 * @argv: argv
 * Return: int
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char *str = NULL, opstr[1024];
	int line = 1, factor = 0;
	size_t count = 0;
	FILE *i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack_t(head);
		exit(EXIT_FAILURE);
	}
	i = fopen(argv[1], "r");
	if (i == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_stack_t(head);
		exit(EXIT_FAILURE);
	}
	while (getline(&str, &count, i) != -1)
	{
		if (kabir(str, opstr, &factor) == -1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opstr);
			free_stack_t(head);
			exit(EXIT_FAILURE);
		}
		else
		{
			ops[kabir(str, opstr, &factor)].f(&head, factor);
		}
		++line;
	}
	free_stack_t(head);
	return (0);
}
