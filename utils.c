#include "monty.h"

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
		tok = strtok(str, " ");
		if (tok == NULL)
			break;
		tokenz[i] = malloc(sizeof(char) * (strlen(tok) + 1));;
		strcpy(tokenz[i], tok);
	}
	tokenz[i] = NULL;
	return (tokenz);
}

void opcode_delegator(char **tokz)
{
	int i;
	stack_t *new_node = NULL;

	if (tokz[1] != NULL)
	{
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{

		}
		new_node->n = tokz[i];
		new_node->next = NULL;
		new_node->prev = NULL;
	}
}
