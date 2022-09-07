#include "shell.h"

int a_delimeter(const char *delimeter, char c);
/**
 * tokenization - split a string
 * @str: string to split
 * @delim: charcter to split str
 * Return: pointer to new or NULL
 */
char **tokenization(char *str, const char *delim)
{
	int k = 0, j = 0, i = 0, size = 0, lens[1200];
	char **arr;

	if (str == NULL || !(*str))
		return (NULL);
	/* calc no of words and lengths */
	for (i = 0; str[i]; i++)
	{
		/* skip delimeters */
		if (a_delimeter(delim, str[i]))
			continue;
		/* get the word length */
		j = i;
		while (!a_delimeter(delim, str[i]) && str[i])
			i++;
		if (i > j)
			lens[size++] = i - j;
		if (!str[i])
			break;
	}
	if (!size)
		return (NULL);
	/* create array of strings */
	arr = malloc((size + 1) * sizeof(char *));
	for (i = 0; str[i]; i++)
	{
		if (a_delimeter(delim, str[i]))
			continue;
		/* copy the word */
		arr[k] = malloc((lens[k] + 1) * sizeof(char));
		j = 0;
		while (!a_delimeter(delim, str[i]) && str[i])
			arr[k][j++] = str[i++];
		arr[k++][j] = '\0';
		if (!str[i])
			break;
	}
	arr[size] = NULL;
	return (arr);
}

/**
 * a_delimeter - check if a character is in delimeter
 * @delimeter: pointer to delimeters
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
