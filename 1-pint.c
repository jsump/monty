#include "monty.h"
/**
 * pint - print value at top of stack followed by new line
 * @stack: stack of elements
 * @line_number: number of line where element should be
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
