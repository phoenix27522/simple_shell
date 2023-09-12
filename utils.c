#include "shell.h"

/**
 * _strlen - finds the length of a string
 * @str: string
 *
 * Return: length of str
 */
unsigned int _strlen(const char *str)
{
	unsigned int i = 0;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
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
 *_strdup - returns a pointer to a new string
 *which is a duplicate of the string str
 *@str: string
 *
 *Return: pointer to the duplicated string, or NULL
 *
 */
char *_strdup(const char *str)
{
	unsigned int len, i = 0;
	char *new_str;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	new_str = malloc(sizeof(char) * len + 1);

	if (new_str == NULL)
		return (NULL);
	while ((new_str[i] = str[i]) != '\0')
		++i;
	return (new_str);
}

/**
 *str_concat - concatenates two strings.
 *@s1: first string
 *@s2: second string
 *
 *Return: concatenated string.
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len, i = 0;
	char *str;

	len = (s1 == NULL ? 0 : _strlen(s1)) + (s2 == NULL ? 0 : _strlen(s2));

	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (NULL);

	while (s1 != NULL && (str[i] = *s1) != '\0')
		i++, s1++;
	while (s2 != NULL && (str[i] = *s2) != '\0')
		i++, s2++;
	str[i] = '\0';

	return (str);
}
