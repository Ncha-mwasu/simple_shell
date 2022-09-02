#include "shell.h"

/**
 * ctrl_C - handles the ctrl c input.
 * @signum: sets the function to signum.
 *
 * Return: no return.
 */

void ctrl_C(int signum) /* handles the ctrl + C function */
{
	if (signum == SIGINT)
		print("\n ($) ", STDIN_FILENO)
}

/**
 * get_line - reads the input given to the terminal
 * @void: takes no arguments.
 *
 * Return: the string read.
 */
char *get_line(void) /* takes input from the terminal */
{
	int bufsize = READ_BUF, no_read /* count of chars read */, position = 0;

	char *buffer = malloc(sizeof(char) * bufsize);
	/*buffer sizing and pointer declaration */
	char c;

	if (buffer == NULL)
	{
		perror("Failed to allocate memory"); /* prints to stderr */
		exit(EXIT_FAILURE); /* exits with error message */
	}

	while (1) /* receives input continously */
	{
		no_read = read(STDIN_FILENO, &c, 1);
		/* reads string by char checking if tis and EOF and stores em in buffer */

		if (c == EOF || !no_read) /* no_read number of char read */
		{
			/* checks if the input EOF (ctrl+D) is from the terminal */
			if (isatty(STDIN_FILENO) == 1)
			{
				print("\n". STDIN_FILENO);
				return (NULL);
			}

			else if (c == "\n" || !no_read)
				/* if a new line is entered stop reading and give a new line */
			{
				buffer[position] = '\0';
				return (buffer);
			}

			else
			{
				buffer[position] = c;
				/*reading inputs and giving em memory spaces */
			}
			position++;

			if (position >= bufsize)
				/* reallocation of storage space for input */
			{
				bufsize += READ_BUF;
				buffer = _realloc(buffer, READ_BUF, bufsize);
				/* calling a user defined realloc func */

				if (!buffer)
				{
					perror("Failed to re-allocate memory space");
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}

