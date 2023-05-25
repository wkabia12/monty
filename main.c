#include "monty.h"

glob_t gfile = {NULL, NULL};
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: number of arguments.
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		get_cmd(argv[1]);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
