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
/**
 * _strstr - Entry point
 * @haystack: input
 * @needle: input
 * Return: Always 0 (Success)
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;

	if (*needle == '\0')
	{
		return (haystack);
	}

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0' && haystack[i + j] == needle[j]; j++)
			;
		if (needle[j] == '\0')
		{
			return (&haystack[i]);
		}
	}
	return ('\0');
}
/**
 * _strncat - concatinates most n char from z string src to string dest
 * @dest: pointer to z destination string, where z src string concates
 * @src: pointer to z source string,which char will be appended to dest
 * @n: maximum number of char to be taken from src and concat to dest
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;
	int length = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		length++;
	}

	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[length + j] = src[j];
	}

	dest[length + j] = '\0';

	return (dest);
}

