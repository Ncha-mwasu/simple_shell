#include "shell.h"

/**
 * main - starts the shell and initiates the shell loop.
 * 
 * @argc: counts the arguments passed on the terminal.
 * @argv: double char pointer to an array that holds the arguments
 * 	  passed on the terminal.
 *
 * Return: 1 on success.
 */

int main (int argc __atribute__((unused)), char **argv)
{
	char *line;
	char **args;

	(void) argv;

	signal(SIGINT, ctrl_C);

	while (1)
	{
		_print(" ($) ", STDOUT_FILENO);
		line = _getline();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				break;
		}

		args = token(line, DELIMETER);
		execute_shell(args);
	}
	return (1);
}
