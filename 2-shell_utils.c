#include "shell.h"

/**
 * tokenize - split a string
 * @str: string to split
 * @delim: charcter to split str
 * Return: pointer to new or NULL
 */
char **tokenization(char *str, const char *delim)
{
	int k = 0, j = 0, i = 0, size = 0, len[1200];
	char **arr /* an array of arrays */

	if (str == NULL || !(*str))
		return NULL;
	/* loops to get the number of words iputted */
	for (; str[i]; i++)
	{
		/*checks for delimeters and skips them 
		 * using the continue func */
		if (a_delimeter(delim, str[i]))
			continue; /* skips the delimeter */
		/* gets the length of a word */
		j = i;

		while (!a_delimeter(delim, str[i]) && str[i])
			i++;
		if (i > j)
			len[size++] = i - j;
		if (!str[i])
			break;
	}

