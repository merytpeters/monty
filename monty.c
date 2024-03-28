#include "monty.h"

void parse_file(FILE *stream)
{
	char *line;
	int line_count, len = 20;
	char **tokz;

	line_count = 0;
	line = malloc(sizeof(char) * 20);
	do {
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
				fprintf(stderr, "L%d: unknown instruction %s\n", line_count, tokz[0]);
				exit(EXIT_FAILURE);
			}
			else
			{
				opcode_delegator(tokz);
				free_vec(tokz);
			}
		}
	} while (line != NULL);
	fprintf(stdout, "Done reading file");
	free(line);
}

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
	printf("file opened successfully!\n");
	parse_file(my_file);
	fclose(my_file);
	return (0);
}
