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

	free(*stack);
	moving_pointer = head;
	stack_count = 0;
	if (head != NULL)
		stack_count = 1;
	while (head != NULL && moving_pointer->next != NULL)
	{
		stack_count++;
		moving_pointer = moving_pointer->next;
	}
	if (stack_count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	if (moving_pointer->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
	}
	quotient = (moving_pointer->prev)->n / moving_pointer->n;
	(moving_pointer->prev)->n = quotient;
	pop(stack, line_count);
}

/**
 * mod - Division opcode function
 * @stack: The stack
 * @line_count: The number of elements in the stack
 */
void mod(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	int stack_count;
	int mod;

	free(*stack);
	moving_pointer = head;
	stack_count = 0;
	if (head != NULL)
		stack_count = 1;
	while (head != NULL && moving_pointer->next != NULL)
	{
		stack_count++;
		moving_pointer = moving_pointer->next;
	}
	if (stack_count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	if (moving_pointer->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_count);
		exit(EXIT_FAILURE);
	}
	mod = (moving_pointer->prev)->n % moving_pointer->n;
	(moving_pointer->prev)->n = mod;
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

	free(*stack);
	moving_pointer = head;
	stack_count = 0;
	if (head != NULL)
		stack_count = 1;
	while (head != NULL && moving_pointer->next != NULL)
	{
		stack_count++;
		moving_pointer = moving_pointer->next;
	}
	if (stack_count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		exit(EXIT_FAILURE);
	}
	multiply = (moving_pointer->prev)->n * moving_pointer->n;
	(moving_pointer->prev)->n = multiply;
	pop(stack, line_count);
}
