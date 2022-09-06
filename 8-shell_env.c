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

void quit(char **commands)
{
	(void) commands;
}

void ch_dir(char **commands/*, path_hist *ptr*/)
{
	/* char *home;
	home = getenv("HOME");
	if (command[1] == NULL)
	{	set pre*/

	(void) commands;
}
