#include "shell.h"
/**
 * _getline - function to read input
 *takes nothing
 *Return: nothing(test purposes)
 */
char *_getline(void)
{
	size_t n = 0;
	ssize_t result, _write;
	/*remove this */
	char *buffer = NULL;

	_write = write(1, "$", 1);
	if (_write == -1)
	{
		perror("An error has occured");
	}
	result = getline(&buffer, &n, stdin);
	if (result == -1)
	{
		free(buffer);
		perror("An error occured");
		exit(1);
	}
	return (buffer);
}
