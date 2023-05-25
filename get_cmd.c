#include "monty.h"
#define MAX 100

/**
 * get_cmd - Read file
 * @argv: Arguments
 * Return: Nothing
 */
void get_cmd(char *argv)
{
	stack_t *stack = NULL;
	int lcount = 0, res = 0;
	char *args = NULL, *val = NULL;

	gfile.fd = fopen(argv, "r");
	gfile.line = malloc(MAX);
	if (gfile.line == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
		
	}
	if (gfile.fd)
	{
		while (fgets(gfile.line, MAX , gfile.fd) != NULL)
		{
			lcount++;
			args = strtok(gfile.line, " \n\t\r");
			if (args == NULL)
			{
				free(args);
				continue;
			}
			else if (*args == '#')
				continue;
			val = strtok(NULL, " \n\t\r");
			res = get_opcds(&stack, args, val, lcount);
			if (res == 1)
				err_push(gfile.fd, gfile.line, stack, lcount);
			else if (res == 2)
				err_ins(gfile.fd, gfile.line, stack, args, lcount);
		}
		free(gfile.line);
		free_stk(stack);
		fclose(gfile.fd);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
