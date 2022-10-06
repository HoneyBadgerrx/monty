#include "monty.h"
instruction_t ops[] = {
	{"push", push},
	{"pall", pall},
	{"nop", nop},
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
	char *str = NULL, *opstr = NULL;
	int line = 1;
	size_t count = 0;
	FILE *i;

	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		free_stack_t(head);
		exit(EXIT_FAILURE);
	}
	i = fopen(argv[1], "r");
	if (i == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		free_stack_t(head);
		exit(EXIT_FAILURE);
	}
	while (getline(&str, &count, i) != -1)
	{
		if (kabir(str, opstr) == -1)
		{
			fprintf(stdout, "L%d: unknown instruction %s\n", line, opstr);
			free_stack_t(head);
			exit(EXIT_FAILURE);
		}
		else
			ops[kabir(str, opstr)].f(&head, line);
		++line;
	}
	free_stack_t(head);
	return (EXIT_SUCCESS);
}
