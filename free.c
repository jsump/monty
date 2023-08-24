#include "monty.h"
/**
 * free_the_stack - free stack nodes
 * @stack: stack of elements
 */
void free_the_stack(stack_t *stack)
{
	while (stack)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
}
