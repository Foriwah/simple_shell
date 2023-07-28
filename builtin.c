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
		for (; (environ != NULL) && (environ[i] != NULL); i++)
		{
			puts(environ[i]);
		}
		if (argv != NULL)
		{
			for (; (argv[i] != NULL); i++)
				free(argv[i]);
			free(argv);
		}
		return (0);
	}
	return (1);
}
