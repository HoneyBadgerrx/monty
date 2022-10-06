#include "monty.h"

/**
 * m_add - add the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	m_pop(stack, line_number);
	(*stack)->n += n;
}
/**
 * m_mul - multiply top two elements of stack and push result
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	int n;

	if (var.stack_len < 2)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	m_pop(stack, line_number);
	(*stack)->n *= n;
}
