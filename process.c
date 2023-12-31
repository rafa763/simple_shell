#include "headers.h"

#define MAX_ARGS 200

/**
 * process - takes user input and tokenize it to reach final executable command
 * @input: user input from command line
 * Return: command stats value
 */
int process(char *input)
{
	char *token, *command, *args[MAX_ARGS];
	int argcount = 0, stat;
	char buff[1024];

	strcpy(buff, input);
	token = strtok(buff, " ");
	command = token;
	args[argcount++] = token;
	while (token && argcount < MAX_ARGS)
	{

		token = strtok(NULL, " ");
		args[argcount++] = token;
	}
	args[argcount] = NULL;

	if (strcmp(command, "env") == 0)
		stat = _getenv();
	else if (strcmp(command, "setenv") == 0)
		stat = _setenv(args[1], args[2], 1);
	else if (strcmp(command, "unsetenv") == 0)
		stat = _unsetenv(args[1]);
	else if (strcmp(command, "exit") == 0)
		exit(0);
	else
		stat = checkcommand(command, args);

	return (stat);
}
