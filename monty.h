#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - global and its funcs
 * @fd: File descriptor
 * @line: Line to getline
 *
 * Description: To handle the file and getline
 */
typedef struct glob_s
{
	FILE *fd;
	char *line;
} glob_t;

extern glob_t gfile;
extern int digit;

void get_cmd(char *argv);
int get_opcds(stack_t **stack, char *arg, char *item, int lcount);

void push_opcd(stack_t **stack, unsigned int line_no);
void pall_opcd(stack_t **stack, unsigned int line_no);
void pint_opcd(stack_t **stack, unsigned int line_no);
void swap_opcd(stack_t **stack, unsigned int line_no);
void pop_opcd(stack_t **stack, unsigned int line_no);
void add_opcd(stack_t **stack, unsigned int line_no);
void sub_opcd(stack_t **stack, unsigned int line_no);
void nop_opcd(stack_t **stack, unsigned int line_no);

void free_stk(stack_t *stack);
void clr_stk(stack_t **stack);
int chk_digit(char *c);
stack_t *new_node(int n);
void err_push(FILE *fd, char *line, stack_t *stack, int lcount);
void err_ins(FILE *fd, char *line, stack_t *stack, char *lcount, int val);
#endif /*MONTY_H*/
