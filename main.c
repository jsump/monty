#include "monty.h"

void process_inst(char *token, stack_t **stack, unsigned int line_number);
void process_file(FILE *fp, stack_t **stack);

/**
 * main - entry point of monty program
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *fp;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	process_file(fp, &stack);
	return (EXIT_SUCCESS);
}

/**
 * process_inst - this fuction processes instructions
 * @token: instruction token
 * @stack: stack of elements
 * @line_number: number of line with instruction
 */
void process_inst(char *token, stack_t **stack, unsigned int line_number)
{
	int n;

	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \n");

		if (!token || (!isdigit(*token) && *token != '-' && *token != '+'))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		n = atoi(token);
		if (n != 0 || *token == '0')
			push(stack, n);
	}
	else if (strcmp(token, "pall") == 0)
		pall(*stack);
	else if (strcmp(token, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(token, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(token, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(token, "add") == 0)
		add(stack, line_number);
	else if (strcmp(token, "nop") == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
		fflush(stderr);
		exit(EXIT_FAILURE);
	}
}

/**
 * process_file - process monty bytecode file
 * @fp: file pointer of bytecode file
 * @stack: stack of elements
 */
void process_file(FILE *fp, stack_t **stack)
{
	char *line = NULL, *token;
	size_t len = 1024;
	unsigned int line_number;

	line_number = 0;
	line = (char *)malloc(len);

	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, len, fp) != NULL)
	{
		line_number++;
		token = strtok(line, " \n");
		process_inst(token, stack, line_number);
	}
	free(line);
	fclose(fp);
}
