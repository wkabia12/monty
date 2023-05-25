#include "monty.h"
int digit;

/**
 * get_opcds - function to handle the opcode
 * @stack: is a stack or queue
 * @args: is a parameter
 * @val: is a parameter
 * @lcount: is a line command
 * Return: nothing
 */
int get_opcds(stack_t **stack, char *args, char *val, int lcount)
{
	int i = 0;

	instruction_t opcds[] = {
		{"push", push_opcd},
		{"pall", pall_opcd},
		{"pint", pint_opcd},
		{"pop", pop_opcd},
		{NULL, NULL}
	};

	while (opcds[i].opcode)
	{
		if (!strcmp(args, opcds[i].opcode))
		{
			if (!strcmp(args, "push"))
			{
				if (chk_digit(val) == 1)
				{
					digit = atoi(val);
				}

				else
					return (1);
			}
			opcds[i].f(stack, (unsigned int)lcount);
			break;
		}
		i++;
	}
	if (!opcds[i].opcode)
		return (2);

	return (0);
}
