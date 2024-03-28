#include "monty.h"

void parse_file(FILE *stream)
{
	char *line;
	int line_count;
	int len = 20;

	line_count = 0;
	do {
		line = fgets(line, len, stream);
		if (line == NULL)
		{
			break;
		}
		else
		{
			line_count++;
			fprintf(stdout, "Line %d says: %s", line_count, line);
		}
	} while (line != NULL);
	fprintf(stdout, "Done reading file");
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
