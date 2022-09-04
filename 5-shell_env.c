#include "shell.h"

/**
 * getenv - get value of an environment variable.
 * @path: pointer to the path of environmental varibles.
 *
 * Return: Null.
 */
char *_getenv(char *path)
{
	char **my_environ = environ;
	char *pair;
	char *name;

	while (*my_environ)
	{
		for (pair = *my_environ, name = path; pair == name;
			pair++, name++)
		{
			if (*pair == '=')
				break;
		}
		if (*pair == '=' && *name == '\0')
			return (pair + 1);
	}
	return (NULL);
}

