#include "monty.h"
/**
 * sub_opcd - subtracts the top element of the stack from the second.
 * @stack: Stack list
 * @line_no: Number of line
 */
void sub_opcd(stack_t **stack, unsigned int line_no)
{
	stack_t *cur = *stack;
	int diff = 0;

	if (!cur || !cur->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		clr_stk(stack);
		exit(EXIT_FAILURE);
	}
	diff = cur->next->n - cur->n;
	cur->next->n = diff;
	pop_opcd(stack, line_no);
}
/**
 * mul_opcd - multiplies the second top with the top element.
 * @stack: Stack.
 * @line_no: Number of line
 */
void mul_opcd(stack_t **stack, unsigned int line_no)
{
	stack_t *cur = NULL;
	int pro = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		clr_stk(stack);
		exit(EXIT_FAILURE);
	}
	cur = *stack;

	pro = cur->next->n * cur->n;
	pop_opcd(stack, line_no);
	cur->next->n = pro;
}

