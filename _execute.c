#include "main.h"
/**
 * execute - execute commands
 * @command: commands array
 * @av: arguments array
 * @index: index of the line
 *
 * Return: status
*/
int execute(char **command, char **av, int index)
{
	pid_t fork_result;
	int status = 0;
	char *path = NULL;

	path = _getpath(command[0]);
	if (path == NULL)
	{
		error_print(av, command[0], index);
		free(path), path = NULL;
		free2d(command), command = NULL;
		return (127);
	}
	fork_result = fork();

	if (fork_result == 0)
	{
		if (execve(path, command, environ) == -1)
		{
			perror(av[0]);
			free2d(command), path = NULL;
			free(path), path = NULL;
			return (127);
		}
	}
	else
	{
		waitpid(fork_result, &status, 0);
		free2d(command), command = NULL;
		free(path), path = NULL;
	}
	return (WEXITSTATUS(status));
}
