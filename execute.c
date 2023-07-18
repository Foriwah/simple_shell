#include "shell.h"

/**
 * execute - Our execute function
 */

void execute(void)
{
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", NULL};

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		/*free(argv);*/
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			/*free(argv);*/
			exit(1);
		}
	}
	else
		wait(NULL);
	/*free(argv);*/
}
