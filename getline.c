#include "shell.h"

/**
 * _getline - reads an entire line from stream,
 * storing the address of the buffer containing
 * text into *lineptr
 * @lineptr: pointer to string
 * @n: bytes count
 * @stream: FILE Stream
 *
 * Return: number of characters read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t len = 0;
	ssize_t nread;
	int c;
	char *line, *new_line;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{	*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	line = *lineptr;
	while (1)
	{	nread = read(fileno(stream), &c, 1);
		if (nread <= 0)
		{
			if (len == 0)
				return (-1);
			break;
		}
		line[len++] = (char)c;
		if (len + 1 >= *n)
		{	*n *= 2;
			new_line = _realloc(line, sizeof(line), *n);
			if (new_line == NULL)
			{	free(line);
				return (-1);
			}
			line = new_line;
			*lineptr = line;
		}
		if ((char)c == '\n')
			break;
	}
	line[len] = '\0';
	return (len);
}
