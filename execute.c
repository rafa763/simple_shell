#include "headers.h"
/**
 *checkcommand-checks the validaity of user input
 *@command:user input after executable found
 *@args:commandline argument
 *Return:status of executable file
 **/
int checkcommand(char *command, char **args)
{
	int stat;
	char *result, *prompt;
	pid_t pid;

	result = getpath(command);
	prompt = "command not found\n";
	if (!result)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		return (-1);
	}

	pid = fork();
	if (pid < 0)
		perror("Error in forking");
	else if (pid == 0)
	{
		execve(result, args, environ);
		perror("Error in child");
	}
	else
	{
		wait(&stat);
		return (stat);
	}

	return (stat);
}
