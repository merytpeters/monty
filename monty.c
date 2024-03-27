#include "monty.h"

int main(int argc, char **argv)
{
	FILE *my_file;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	my_file = fopen(argv[1], "r");
	if (my_file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	printf("file opened successfully!\n");
	return (0):
}
