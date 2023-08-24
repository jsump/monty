#include "monty.h"
/**
 * pall - prints all the values in a stack
 * @stack: stack of elememts
 */
void pall(stack_t *stack)
{
	stack_t *curr = stack;

	while (curr)
	{
		if (curr->print_flag)
		{
			printf("%d\n", curr->n);
			fflush(stdout);
		}
		curr = curr->next;
	}
}
