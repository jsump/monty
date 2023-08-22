#include "main.h"
/**
 * pall - prints all the values in a stack
 * @stack: stack of elememts
 */
void pall(stack_t *stack)
{
	stack_t *curr = stack;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
