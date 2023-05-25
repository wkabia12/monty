#include "monty.h"

/**
 * push_opcd - push item
 * @stack: is a parameter
 * @line_no: is value
 */
void push_opcd(stack_t **stack, unsigned int line_no)
{
	stack_t *new = NULL;
	(void)line_no;

	new = new_node(digit);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * pall_opcd - print elements stack
 * @stack: is a parameter
 * @n: is value
 * Return: nothing
 */
void pall_opcd(stack_t **stack, unsigned int n)
{
	stack_t *cur = NULL;
	(void)n;

	cur = *stack;

	while (cur != NULL)
	{
		fprintf(stderr, "%d\n", cur->n);
		cur = cur->next;
	}
}
/**
 * pint_opcd - prints the value at the top of the stack.
 * @stack: Stack list
 * @line_no: Number of the line
 */
void pint_opcd(stack_t **stack, unsigned int line_no)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		clr_stk(stack);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stderr, "%d\n", (*stack)->n);
}
/**
 * pop_opcd - removes the top element of the stack.
 * @stack: Stack list
 * @line_no: Number of the line
 */
void pop_opcd(stack_t **stack, unsigned int line_no)
{
	stack_t *cur = NULL;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		clr_stk(stack);
		exit(EXIT_FAILURE);
	}

	cur = *stack;

	*stack = cur->next;
	if (cur->next != NULL)
		cur->next->prev = cur->prev;
	free(cur);
}
