#include "monty.h"

/**
 * push - push opcode function
 * @stack: The stack
 * @line_count: number of elements in the stack
 */
void push(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;

	if (!head)
	{
		head = *stack;
		return;
	}
	if (stack == NULL)
	{
		printf("L%d: usage: push integer\n", line_count);
		free_stack(head);
		exit(EXIT_FAILURE);
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

	free(*stack);
	moving_pointer = head;
	if (head == NULL)
		return;
	while (moving_pointer->next != NULL)
		moving_pointer = moving_pointer->next;
	while (moving_pointer != NULL)
	{
		fprintf(stdout, "%d\n", moving_pointer->n);
		moving_pointer = moving_pointer->prev;
	}
}
/**
 * pint - print the top of the stack
 * @stack: The stack
 * @line_count: Number of elements in the stack
 */
void pint(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;

	free(*stack);
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		moving_pointer = head;
		while (moving_pointer->next != NULL)
			moving_pointer = moving_pointer->next;
		printf("%d\n", moving_pointer->n);
	}
}
/**
 * pop - remove the top of the stack
 * @stack: The stack
 * @line_count: Number of elements in the stack
 */
void pop(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;

	free(*stack);
	if (head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	moving_pointer = head;
	while (moving_pointer->next != NULL)
		moving_pointer = moving_pointer->next;
	if (moving_pointer->prev == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		(moving_pointer->prev)->next = NULL;
		free(moving_pointer);
	}
}

/**
 * swap - swap the top two elements of the  stack
 * @stack: The stack
 * @line_count: Number of elements in the stack
 */
void swap(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	int temp;
	int stack_count;

	free(*stack);
	stack_count = 0;
	if (head != NULL)
		stack_count = 1;
	moving_pointer = head;
	while (moving_pointer != NULL && moving_pointer->next != NULL)
	{
		stack_count++;
		moving_pointer = moving_pointer->next;
	}
	if (stack_count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	temp = moving_pointer->n;
	moving_pointer->n = (moving_pointer->prev)->n;
	(moving_pointer->prev)->n = temp;
}
