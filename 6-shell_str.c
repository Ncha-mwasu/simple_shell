#include "shell.h"

/**
 * strlen - function to calculate the length of a string.
 *@str: pointer to a string.
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
 * strcmp: compares two strings
 *@str1: pointer to the first string
 *@str2: pointer to second string
 *
 * Return: returns numeric values 
 */
{
	int count1 = _strlen(str1);
	int count2 = _strlen(str2);
	int i = 0, q = 0;

	while (str[i])
	{
		if (str1[i] != str2[i])
			q = str1[i] - str2;
			return (q);
		i++;
	}
	return (0);
}
