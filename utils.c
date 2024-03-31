#include "monty.h"

stack_t *head = NULL;
/**
 * validate_command - Checks for opcodes in the array
 * @opcode: opcode we want to check
 * Return: 1 if opcode is valid and 0 if not
 */
int validate_command(char *opcode)
{
	char *allopcodes[] = {"push", "pall", "pint", "pop", "swap",
		"add", "nop", "sub", "div", "mul", "mod", "pchar",
		"pstr", "rotl", "rotr", "stack", "queue", NULL};
	int i = 0;

	while (allopcodes[i] != NULL)
	{
		if ((strcmp(opcode, allopcodes[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * tokenizer - Tokenizes a string into an array of strings
 * @line: Input string to tokenize
 * Return: Array of tokens
 */
char **tokenizer(char *line)
{
	char **tokenz;
	char *str;
	char *tok;
	int i;

	tokenz = malloc(sizeof(char *) * 3);
	if (tokenz == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0, str = line; i < 2 ; i++, str = NULL)
	{
		tok = strtok(str, " \n");
		if (tok == NULL)
			break;
		tokenz[i] = malloc(sizeof(char) * (strlen(tok) + 1));
		strcpy(tokenz[i], tok);
	}
	tokenz[i] = NULL;
	return (tokenz);
}

/**
 * opcode_delegator - Delegates the execution of an opcode to its function
 * @tokz: Array of tokens containing the opcode
 * @line_count: Line number in the input file
 */
void opcode_delegator(char **tokz, unsigned int line_count)
{
	int i;
	stack_t *new_node = NULL;
	instruction_t ins_list[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", nop}, {"sub", sub},
		{"div", divv}, {"mul", mul},
			/**
			* {"mod", mod},
			* {"pchar", pchar},
			* {"pstr", pstr},
			* {"rotl", rotl},
			* {"rotr", rotr},
			* {"stack", stack},
			* {"queue", queue}
			*/
	};

	if (tokz[1] != NULL)
	{
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new_node->n = atoi(tokz[1]);
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	i = 0;
	while (i < 10)
	{
		if ((strcmp((ins_list[i]).opcode, tokz[0])) == 0)
		{
			(ins_list[i]).f(&new_node, line_count);
			break;
		}
		i++;
	}
}
/**
 * free_stack - A function that takes a doubly linked list
 * and frees them
 * @stack: The list we want  to free
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
