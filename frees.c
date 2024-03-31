#include "monty.h"

/**
 *free_stack - A function that takes a doubly linked list
 *and frees them
 *@stack: The list we want  to free
 */
void free_stack(stack_t *stack)
{
	stack_t *next_stack;

	while (stack != NULL)
	{
		next_stack = stack->next;
		free(stack);
		stack = next_stack;
	}
}

/**
 *free_vec - A function that takes an array of strings
 * and frees them
 * @vec: the array of strings
 */
void free_vec(char **vec)
{
	int i;

	i = 0;
	while (vec[i] != NULL)
	{
		free(vec[i]);
		i++;
	}
	free(vec);
}
