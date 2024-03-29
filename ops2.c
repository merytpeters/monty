#include "monty.h"

void add(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	int stack_count;
	int sum;

	moving_pointer = head;
	stack_count = 0;
	while (head != NULL && moving_pointer->next != NULL)
	{
		stack_count++;
		moving_pointer = moving_pointer->next;
	}
	if (stack_count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	sum = moving_pointer->n + (moving_pointer->prev)->n;
	(moving_pointer->prev)->n = sum;
	pop(stack, line_count);
}

void nop(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;
	return;
}

void sub(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	int stack_count;
	int diff;

	moving_pointer = head;
	stack_count = 0;
	while (head != NULL && moving_pointer->next != NULL)
	{
		stack_count++;
		moving_pointer = moving_pointer->next;
	}
	if (stack_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	diff = (moving_pointer->prev)->n - moving_pointer->n;
	(moving_pointer->prev)->n = diff;
	pop(stack, line_count);
}
