#include "shell.h"
/**
 * _getline - function to read input
 *takes nothing
 *Return: nothing(test purposes)
 */
char *_getline(void)
{
	size_t n = 0;
	ssize_t result;
	/*remove this */
	char *buffer = NULL;

	printf("# ");
	result = getline(&buffer, &n, stdin);
	if (result == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(buffer);
			exit(0);
		}
		else
		{
			/**
			 * perror("An error occured");
			 */
			exit(0);
		}
		return (NULL);
	}
	return (buffer);
}
