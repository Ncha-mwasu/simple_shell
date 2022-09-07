#include "shell.h"

/**
 * print - outputs to the terminal.
 * @var: variable.
 * @fd: file description.
 *
 * Return: returns the result of input to the terminal.
 */
int print(char *var, int fd)
{
	return (write(fd, var, _strlen(var)));
}

/**
 * _getfunc - checks for an inbuilt function.
 * @command: inbuilts given on the terminal.
 *
 * Return: the func or NULL.
 *
void (*_getfunc(char *command))(char **)
{
	int i;

	map_func map[] = {
		{"env", env},
		{"cd", ch_dir},
		{"exit", quit}
	};

	for (i = 0; i < 3; i++)
	{
		if (_strcmp(command, map[i].cmd_name) == 0)
			return (map[i].func);
	}
	return (NULL);
}
*/
