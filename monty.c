#include "monty.h"

/**
 * parse_file - parses through files
 * @stream: File
 */
void parse_file(FILE *stream)
{
	unsigned int line_count, len = 100;
	char **tokz;
	char line[100];

	line_count = 0;
	while (fgets(line, len, stream) != NULL)
	{
		line_count++;
		tokz = tokenizer(line);
		if (!tokz)
		{
			break;
		}
		if (tokz[0][0] == '#')
		{
			free_vec(tokz);
			continue;
		}
		if (!validate_command(tokz[0]))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, tokz[0]);
			fclose(stream);
			free_vec(tokz);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
		else
		{
			opcode_delegator(tokz, line_count);
		}
	}
	free_stack(head);
}

/**
 * main - checks the number of arguments
 * @argc: Number of arguments
 * @argv: argument vectors
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	FILE *my_file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	my_file = fopen(argv[1], "r");
	if (my_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	parse_file(my_file);
	fclose(my_file);
	return (0);
}
