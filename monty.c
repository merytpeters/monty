#include "monty.h"

/**
 * parse_file - parses through files
 * @stream: File
 */
void parse_file(FILE *stream)
{
	char *line;
	unsigned int line_count, len = 20;
	char **tokz;

	line_count = 0;
	do {
		line = malloc(sizeof(char) * 20);
		line = fgets(line, len, stream);
		if (line == NULL)
		{
			break;
		}
		else
		{
			line_count++;
			tokz = tokenizer(line);
			if (!tokz)
				return;
			if (!validate_command(tokz[0]))
			{
				fprintf(stderr, "L%d: unknown instruction %s", line_count, tokz[0]);
				free(line);
				exit(EXIT_FAILURE);
			}
			else
			{
				opcode_delegator(tokz, line_count);
				free(line);
			}
		}
	} while (line != NULL);
	free(line);
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
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	parse_file(my_file);
	fclose(my_file);
	return (0);
}
