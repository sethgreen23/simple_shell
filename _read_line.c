#include "main.h"
/**
 * _getline - get the command line
 *
 * Return: number of read characters or -1
*/
char *_getline(void)
{
	char *line = NULL;
	size_t length = 0;
	int num_chars = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	num_chars = getline(&line, &length, stdin);
	if (num_chars == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}
	return (line);
}

