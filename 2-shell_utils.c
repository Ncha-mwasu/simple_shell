#include "shell.h"

/**
 * tokenization - split a string
 * @str: string to split
 * @delim: charcter to split str
 * Return: pointer to new or NULL
 */
char **tokenization(char *str, const char *delim)
{
	int q = 0, j = 0, i = 0, size = 0, len[1200];
	char **arr; /* an array of arrays */

	if (str == NULL || !(*str))
		return (NULL);

	for (i = 0; str[i]; i++)
	{
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
	if (!size)
		return (NULL);

	arr = malloc((size + i) * sizeof(char *));
	for (i = 0; str[i]; i++)
	{
		if (a_delimeter(delim, str[i]))
			continue;/* skips delimeters */
		arr[q] = malloc((len[q] + 1) * sizeof(char));
		j = 0;

		while (!a_delimeter(delim, str[i] && str[i]))
			arr[q][j++] = str[i++];
		arr[q++][j] = '\0';

		if (!str[i])
			break;
	}
	arr[size] = NULL;
	return (arr);
}

/**
 * a_delimeter - check if a character is in delimeter
 * @delimeters: pointer to delimeters
 * @c: character to check
 *
 * Return: 1 for true 0 for false
 */

int a_delimeter(const char *delimeter, char c)
{
	int i = 0;

	if (!delimeter)
		return (0);

	while (delimeter[i])
	{
		if (delimeter[i] == c)
			return (1);
		i++;
	}
	return (0);
}

