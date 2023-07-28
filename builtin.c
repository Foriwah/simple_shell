#include "shell.h"

/**
 * _getenv - get environment function
 * @buffer: the command
 * @argv: the argv
 * Return: an integer
 */

int _getenv(char *buffer, char **argv)
{
	int i = 0;

	if (strcmp(buffer, "env") == 0)
	{
		for (i = 0; (environ != NULL) && (environ[i] != NULL); i++)
		{
			puts(environ[i]);
		}
		if (argv != NULL)
		{
			for (i = 0; (argv[i] != NULL); i++)
				free(argv[i]);
			free(argv);
		}
		return (0);
	}
	return (1);
}

/**
 * myexit - this is my exit
 * @buffer: out input
 * @argv: argument
 */

void myexit(char *buffer, char **argv)
{
	int i;

	if (strcmp(buffer, "exit") == 0)
	{
		free(buffer);
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv);
		exit(0);
	}
}
