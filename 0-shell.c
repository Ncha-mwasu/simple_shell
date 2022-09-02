#include "shell.h"

/**
 * main - starts the shell and initiates the shell loop.
 *
 * @argc: counts the arguments passed on the terminal.
 * @argv: double char pointer to an array that holds the arguments
 *		passed on the terminal.
 *
 * Return: 1 on success.
 */

int main(int argc, char **argv)
{
	char *line;
	char **args;
	int cmd_type;

	unused(argc);

	(void) argv;

	/* dealing with ctrl c */
	signal(SIGINT, ctrl_C);

	while (1)
	{
		_print(" ($) ", STDOUT_FILENO);
		line = get_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				break;
		}
		/* argument initialization */
		args = token(line, DELIMETER);
		cmd_type = check_command(args[0]);
		execute_shell(args);
	}
	return (1);
}
