#include "monty.h"

/**
 * new_node - create new node
 * @n: is a value
 * Return: new node
 */
stack_t *new_node(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}
