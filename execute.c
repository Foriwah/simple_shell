#include "shell.h"

/**
 * tokenize_input - tokenizing input
 * @input: the input
 * Return: return the argv
 */

char **tokenize_input(char *input)
{
	char **argv = NULL;
	int argc = 0;
	char *delim = " \t\n";
	char *token = strtok(input, delim);

	while (token)
	{
		argv = (char **)realloc(argv, (argc + 1) * sizeof(char *));
		if (argv == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		argv[argc] = (char *)malloc(strlen(token) + 1);
		if (argv[argc] == NULL)
		{
			perror("Memory allocation error");
			exit(1);
		}
		strcpy(argv[argc], token);
		argc++;
		token = strtok(NULL, delim);
	}
	argv = (char **)realloc(argv, (argc + 1) * sizeof(char *));
	if (argv == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}
	argv[argc] = NULL;
	return (argv);
}

/**
 * execute - Our execute function
 * @argv: tokenized input
 */

void execute(char **argv)
{
	int i;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
			free(argv);
			exit(1);
		}
	}
	else
		wait(NULL);
	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
