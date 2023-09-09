#include "shell.h"

/**
 * _strlen - finds the length of a string
 * @str: string
 *
 * Return: length of str
 */
unsigned int _strlen(char *str)
{
	if (*str == 0)
		return (0);
	return (1 + _strlen(str + 1));
}

/**
 * _puts - prints a string to STDOUT
 * @str: string
 *
 */
void _puts(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * _strn - replaces the last character of string
 * with a null byte
 * @str: string
 *
 * Return: Updated string
 */
char *_strn(char *str)
{
	unsigned int len = _strlen(str);

	str[len - 1] = '\0';

	return (str);
}
