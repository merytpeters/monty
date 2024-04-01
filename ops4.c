#include "monty.h"

/**
 * pchar - Opcode for displaying the char mapping of an integer
 * @stack: The stack that was created
 * @line_count: The line number for the intstruction
 */

void pchar(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	int n;

	free(*stack);
	moving_pointer = head;
	while (moving_pointer && moving_pointer->next != NULL)
		moving_pointer = moving_pointer->next;
	if (moving_pointer != NULL)
	{
		n = moving_pointer->n;
		if (n >= 0 && n <= 127)
			printf("%c\n", moving_pointer->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_count);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{

		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_count);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - Opcode for displaying the string mapping of all integers
 * @stack: The stack that was created
 * @line_count: The line number for the intstruction
 */

void pstr(stack_t **stack, unsigned int line_count)
{
	stack_t *moving_pointer;
	int n;

	(void)line_count;
	free(*stack);
	moving_pointer = head;
	while (moving_pointer->next != NULL)
		moving_pointer = moving_pointer->next;
	if (moving_pointer != NULL)
	{
		while (moving_pointer)
		{
			n = moving_pointer->n;
			if (n > 0 && n <= 127)
				printf("%c", moving_pointer->n);
			else
			{
				break;
			}
			moving_pointer = moving_pointer->prev;
		}
	}
	printf("\n");
}

/**
 * rotl - Opcode for rotating the stack by one to the left
 * @stack: The node that was created
 * @line_count: The line number for the current instruction
 */

void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *last_pointer;

	(void)line_count;
	free(*stack);
	last_pointer = head;
	while (last_pointer->next != NULL)
		last_pointer = last_pointer->next;
	if (last_pointer != NULL)
	{
		(last_pointer->prev)->next = NULL;
		last_pointer->next = head;
		head->prev = last_pointer;
		head = last_pointer;
		head->prev = NULL;
	}
}

/**
 * rotr - Opcode for rotating the stack by one to the right
 * @stack: The node that was created
 * @line_count: The line number for the current instruction
 */

void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *last_pointer;

	(void)line_count;
	free(*stack);
	last_pointer = head;
	while (last_pointer->next != NULL)
		last_pointer = last_pointer->next;
	if (last_pointer != NULL)
	{
		last_pointer->next = head;
		head->prev = last_pointer;
		head = head->next;
		head->prev = NULL;
		(last_pointer->next)->next = NULL;
	}
}
