#include "shell.h"
/**
 * _getline - function to read input
 *takes nothing
 *Return: nothing(test purposes)
 */
void _getline(void)
{
	size_t n = 0;
	ssize_t result;
	/*remove this */
	char *buffer = NULL;

	printf("=>");

	result = getline(&buffer, &n, stdin);

	if (result == -1)
	{
		free(buffer);
		perror("An error occured");
		exit(1);
	}

	/*return (buffer);*/
	printf("success");
	free(buffer);
}
