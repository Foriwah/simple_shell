#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;
void execute(char **argv, char *executable);
char **tokenize_input(char *input);
int _getenv(char *buffer, char **argv);

#endif
