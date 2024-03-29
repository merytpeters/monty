#include "monty.h"

/**
 * push - push opcode function
 * @stack: The stack
 * @line_count: number of elements in the stack
 */
void push(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	(void)line_count;

	printf("pushed\n");
	if (!head)
	{
		head = *stack;
		return;
	}
	moving_pointer = head;
	while (moving_pointer->next != NULL)
		moving_pointer = moving_pointer->next;
	(*stack)->prev = moving_pointer;
	moving_pointer->next = (*stack);
}

/**
 * pall - print all opcode function
 * @stack: The stack
 * @line_count: Number of elements in the stack
 */
void pall(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	(void) line_count;
	(void)stack;

	moving_pointer = head;
	printf("palled\n");
	while (moving_pointer->next != NULL)
		moving_pointer = moving_pointer->next;
	while (moving_pointer->prev != NULL)
	{
		fprintf(stdout, "%d\n", moving_pointer->n);
		moving_pointer = moving_pointer->prev;
	}
}
