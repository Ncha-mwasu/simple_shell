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

int main(int argc __attribute__((unused)), char **argv)
{
	char *line;
	char **args;
	int i = 0;
	/*int cmd_type;*/


	(void) argv;

	/* dealing with ctrl c */
	signal(SIGINT, ctrl_C);

	while (1)
	{
		print(" ($) ", STDOUT_FILENO);
		line = get_line();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				break;
		}
		/* argument initialization */
		args = tokenization(line, DELIMETER);
		while (args[i])

		printf("<<%s>>\n", args[i++]);
		return (1);
		/*cmd_type = check_command(args[0]);
		execute_shell(args, cmd_type);*/
	}
	return (1);
}
