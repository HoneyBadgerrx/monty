#include "l.h"
void main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char *str = NULL, *opstr = NULL;
	int i, count = 0, n = 0, line = 1, *factor;

	if (argc != 2)
	{
		fprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	i = open(argv[1], O_RDONLY);
	if (i == -1)
	{
		fprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&str, &count, i) != -1)
	{
		if (kabir(str, opstr, factor) == -1)
		{
			fprintf(2, "L%d: unknown instruction \n", line, opstr);
			exit(EXIT_FAILURE);
		}
		else
			ops[kabir(str, opstr, factor)]->f(&head, factor);
		++line;
	}
}
