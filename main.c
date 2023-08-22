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
	char *line = NULL, *token;
	size_t len = 0;
	unsigned int line_number;
	
	stack_t *stack = NULL;
	
	line_number = 0;

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

			if (!token || !isdigit(*token))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(atoi(token));
		}
		else if (strcmp(token, "pall") == 0)
			pall(stack);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
