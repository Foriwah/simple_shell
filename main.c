#include "shell.h"

/**
 * main - main function;
 * Return: something
 */

int main(void)
{
	char *input;
	char **argv;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			input = _getline();
			input[strcspn(input, "\n")] = '\0';
			argv = tokenize_input(input);
			execute(argv);
			free(input);
		}
	}
	else
	{
		input = _getline();
		input[strcspn(input, "\n")] = '\0';
		argv = tokenize_input(input);
		execute(argv);
		free(input);
	}
	return (0);

}
