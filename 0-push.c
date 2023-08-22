#include "main.h"
/**
 * push - pushes ad eleent to the stack
 * @n: integer to be pushed
 */
void push(int n)
{
	stack_t *stack = NULL;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (stack)
	{
		new_node->next = stack;
		stack->prev = new_node;
	}
	else 
		new_node->next = NULL;
	stack = new_node;
}
