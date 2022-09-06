#include "shell.h"

/**
 * _strlen - function to calculate the length of a string.
 * @str: pointer to a string.
 *
 * Return: returns the length of a string.
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings
 * @str1: pointer to the first string
 * @str2: pointer to second string
 *
 * Return: returns numeric values.
 */
int _strcmp(char *str1, char *str2)
{
	int count1 = _strlen(str1);
	int count2 = _strlen(str2);
	int i = 0;

	if (count1 != count2)
	{
		return (-1);
	}

	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}
