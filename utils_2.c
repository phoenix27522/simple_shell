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
