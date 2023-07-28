#include "shell.h"
/**
 * prompt - print prompt in interactive mode
 * Return: NULL
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * main - main function;
 * @argc: argument counter
 * @arg: array of Argument
 * Return: something
 */

int main(int argc, char *arg[])
{
	char **argv;
	size_t n = 0;
	ssize_t result;
	char *buffer = NULL;
	(void)argc;

	while (1)
	{
		prompt();
		result = getline(&buffer, &n, stdin);
		if (result == -1)
		{
			free(buffer);
			exit(0);
		}
		/*buffer[strcspn(buffer, "\n")] = '\0';*/
		argv = tokenize_input(buffer);
		myexit(buffer, argv);
		if (_getenv(buffer, argv) == 0)
			continue;
		execute(argv, arg[0], buffer);
		/*free(buffer);*/
	}
	return (0);

}
