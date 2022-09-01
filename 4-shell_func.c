#include "shell.h"

/**
 * print: outputs to the terminal.
 *@var: variable.
 *@fd: file description.
 *
 * Return: returns the result of input to the terminal.
 */
int print(char *var, int fd)
{
	return (write(fd, var, _strlen(var)));
}

/**
 * getfunc: checks for an inbuilt function.
 *@command: inbuilts given on the terminal.
 *
 * Return: the func or NULL.
 */
void (*_getfunc(char *command))(char **)
{
	int i;
	/* an array of inbuilt commands */
	map_func map[] = {
		{"env", env},
		{"cd", ch_dir},
		{"exit", quit}
	};

	for (i = 0; map[i]; i++)
	{
		if (_strcmp(command, map[i].cmd_name) == 0)
			return (map[i].func);
	}
	return (NULL);
}
