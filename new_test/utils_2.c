#include "shell.h"
/**
 * _strncmp - compare string to the given length
 * @s1: string
 * @s2: string
 * @n: length
 *
 * Return: int
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);

	return (*s1 - *s2);
}

/**
 *_strcmp - compares two strings
 *@s1: first string
 *@s2: second string
 *
 *Return: 0, if S1 and S2 are equal
 *negative value if S1 < S2
 *postive value if S1 > S2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}

/**
 * mem_free - frees memories
 * @n: number of variables
 *
 */
void mem_free(const unsigned int n, ...)
{
	va_list args;
	void *ptr;
	unsigned int i;

	if (n == 0)
		return;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		ptr = va_arg(args, void *);
		free(ptr);
	}
	va_end(args);
}

/**
 * free_commands - Free the commands array
 * @commands: pointer to array of strings
 *
 */
void free_commands(char **commands)
{
	unsigned int i = 0;

	if (!commands)
		return;

	for (i = 0; commands[i] != NULL; i++)
		if (commands[i])
			free(commands[i]);
	free(commands);
}
/**
 * _strchr - locates char from a string
 * @s: string to be ssearched
 * @c: char to be located on the string
 * Return: pointer to the first occurrence of c in  s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)

			return (&s[i]);
	}
	return (0);
}
