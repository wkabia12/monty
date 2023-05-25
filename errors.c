#include "monty.h"

/**
 * err_push - handle push error
 * @fd: is a file desciptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @lcount: is a line command
 */
void err_push(FILE *fd, char *line, stack_t *stack, int lcount)
{
	fprintf(stderr, "L%u: usage: push integer\n", lcount);
	fclose(fd);
	free(line);
	free_stk(stack);
	exit(EXIT_FAILURE);
}

/**
 * err_ins - Error handler
 * @fd: is a file descriptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @count: is a line command
 * @item: number
 */
void err_ins(FILE *fd, char *line, stack_t *stack, char *lcount, int val)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", val, lcount);
	fclose(fd);
	free(line);
	free_stk(stack);
	exit(EXIT_FAILURE);
}
