#include "monty.h"

/**
 * divv - Division opcode function
 * @stack: The stack
 * @line_count: The number of elements in the stack
 */
void divv(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	int stack_count;
	int quotient;

	moving_pointer = head;
	stack_count = 0;
	while (head != NULL && moving_pointer->next != NULL)
	{
		stack_count++;
		moving_pointer = moving_pointer->next;
	}
	if (stack_count < 1)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
		free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if (moving_pointer->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	quotient = (moving_pointer->prev)->n / moving_pointer->n;
	(moving_pointer->prev)->n = quotient;
	pop(stack, line_count);
}

/**
 * mul - Multiplication opcode
 * @stack: The stack
 * @line_count: The number of elements in the stack
 */
void mul(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	int stack_count;
	int multiply;

	moving_pointer = head;
	stack_count = 0;
	while (head != NULL && moving_pointer->next != NULL)
	{
		stack_count++;
		moving_pointer = moving_pointer->next;
	}
	if (stack_count < 1)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		free(line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	multiply = (moving_pointer->prev)->n * moving_pointer->n;
	(moving_pointer->prev)->n = multiply;
	pop(stack, line_count);
}
