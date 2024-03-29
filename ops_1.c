#include "monty.h"

void push(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	(void)line_count;

	if (head == NULL)
	{
		head = *stack;
		return;
	}
	moving_pointer = head;
	while (moving_pointer->next != NULL)
		moving_pointer = moving_pointer->next;
	(*stack)->prev = moving_pointer;
	moving_pointer->next = (*stack);
	return;
}

void pall(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	(void) line_count;
	(void)stack;

	moving_pointer = head;
	while (moving_pointer->next != NULL)
		moving_pointer = moving_pointer->next;
	while (moving_pointer->prev != NULL)
	{
		fprintf(stdout, "%d\n", moving_pointer->n);
		moving_pointer = moving_pointer->prev;
	}
	return;
}
