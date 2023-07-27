#include "shell.h"

/**
 * main - main function;
 * @argc: argument counter
 * @arg: array of Argument
 * Return: something
 */

int main(int argc, char *arg[])
{
	char *input;
	char **argv;
	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			input = _getline();
			input[strcspn(input, "\n")] = '\0';
			argv = tokenize_input(input);
			execute(argv, arg[0]);
			free(input);
		}
	}
	else
	{
		input = _getline();
		input[strcspn(input, "\n")] = '\0';
		argv = tokenize_input(input);
		execute(argv, arg[0]);
		free(input);
	}
	return (0);

}
