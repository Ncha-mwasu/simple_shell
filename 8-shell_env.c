#include "shell.h"

/**
 * env - array of pointers to strings called the environment
 * @command: pointer to command.
 *
 *
 */
void env(char **command __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		print(environ[i++], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * quit - function to exit the shell.
 * @commands: commands given.
 *
 *
 * Return: no return.
 */
void quit(char **commands)
{
	(void) commands;
}

/**
 * ch_dir - function that changes the directory.
 * @commands: pointer to commands
 *
 * Return: No return
 */
void ch_dir(char **commands)
{
	(void) commands;
}
