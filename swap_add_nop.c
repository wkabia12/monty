#include "monty.h"
/**
 * swap_opcd - swaps the top two elements of the stack.
 * @stack: Stack
 * @line_no: Number of the line
 */
void swap_opcd(stack_t **stack, unsigned int line_no)
{
	stack_t *cur = *stack;
	int temp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		clr_stk(stack);
		exit(EXIT_FAILURE);
	}
	temp = cur->n;
	cur->n = cur->next->n;
	cur->next->n = temp;
}
/**
 * add_opcd - function add two integer
 * @stack: Stack list
 * @line_no: Number of the line
 */
void add_opcd(stack_t **stack, unsigned int line_no)
{
	stack_t *cur = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		clr_stk(stack);
		exit(EXIT_FAILURE);
	}
	cur = *stack;
	sum = cur->n + cur->next->n;
	cur->next->n = sum;
	pop_opcd(stack, line_no);
}
/**
 * nop_opcd - function void
 * @stack: Stack list
 * @line_no: Number of the line
 */
void nop_opcd(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
}
