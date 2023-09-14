#include "shell.h"

/**
 * _getline - reads an entire line from stream,
 * storing the address of the buffer containing
 * text into *lineptr
 * @lineptr: pointer to string
 * @size_t: bytes count
 * @stream: FILE Stream
 *
 * Return: number of characters read
 */
 ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
 {
	 ssize_t len = 0;
	 int c;
	 char *line;

	 if (lineptr == NULL || n == NULL || stream == NULL)
		 return (-1);

	 if (*lineptr == NULL)
	 {
		 *n = 128;
		 *lineptr = malloc(*n);

		 if (*lineptr == NULL)
			 return (-1);
	 }

	 line = *lineptr;

	 while (1)
	 {
		 ssize_t nread = read(fileno(stream), &c, 1);

		 if (nread <= 0)
		 {
			 if (len == 0)
				 return (-1);
			 break;
		 }

		 line[len] = (char)c;
		 len++;

		 if (len + 1 >= *n)
		 {
			 char *new_line;

			 *n *= 2;
			 new_line = realloc(line, *n);

			 if (new_line == NULL)
			 {
				 free(line);
				 return (-1);
			 }

			 line = new_line;
			 *lineptr = line;
		 }

		 if ((char)c == '\n')
			 break;
	 }

	 line[len] = '\0';

	 if (len == 0 && EOF)
		 return (-1);

	 return (len);
 }
