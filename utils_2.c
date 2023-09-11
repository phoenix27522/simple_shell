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
 * mem_free - frees memories
 * @n: number of variables
 * 
 */
void mem_free(const unsigned int n, ...)
{
	va_list args;
	void *ptr;
	int i;

	if (n == 0)
		return;

	va_start(args, n);
	for (i = 0; i <n; i++)
	{
		ptr = va_arg(args, void *);
		free(ptr);
	}
	va_end(args);
}
