#include "monty.h"

/**
 * free_stk - Free a list.
 * @stack: Head node.
 * Return: Nothing.
 */
void free_stk(stack_t *stack)
{
	stack_t *cur = NULL;

	cur = stack;

	if (cur != NULL)
	{
		free_stk(cur->next);
		free(cur);
	}
}
/**
 * chk_digit - Checks for a digit 0 through 9
 * Return: 0 or 1
 * @c: Variable
 **/
int chk_digit(char *c)
{
	char *temp = c;

	if (c == NULL)
		return (0);
	if (*temp == '-')
		temp++;

	for (; *temp != '\0'; temp++)
	{
		if ((*temp < '0' || *temp > '9'))
		{
			return (0);
		}
	}
	return (1);
}
/**
 * clr_stk - Frees mallocs and close de files
 * @stack: Stack
 */
void clr_stk(stack_t **stack)
{
	stack_t *c = *stack;

	for (; c; c = *stack)
	{
		*stack = (*stack)->next;
		free(c);
	}
	fclose(gfile.fd);
	free(gfile.line);
}
