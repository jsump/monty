#include "main.h"
/**
 * main - entry point of monty program
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *fp;
	int n;
	char *line = NULL, *token;
	size_t len = 1024;
	unsigned int line_number;

	stack_t *stack = NULL;

	line_number = 0;
	line = (char *)malloc(len);

	if (line == NULL)
	{
		fprintf(stderr, "Error: Memory allocation for line failed\n");
		exit(EXIT_FAILURE);
	}
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
	while (fgets(line, len, fp) != NULL)
	{
		line_number++;
		token = strtok(line, " \n");

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
				push(&stack, n);
		}
		else if (strcmp(token, "pall") == 0)
			pall(stack);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			fflush(stderr);
			exit(EXIT_FAILURE);
		}
	}
	fclose(fp);
	free(line);
	return (EXIT_SUCCESS);
}
