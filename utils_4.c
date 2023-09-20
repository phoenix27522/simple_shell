#include "shell.h"

/**
 *_memcpy - copies n bytes from memory area src to
 *memory area dest.
 *@dest: destination memory
 *@src: memory area to copy from
 *@n: bytes to copy
 *
 *Return: pointer to dest
 */
void *_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned char *d = (unsigned char *)dest;
	const unsigned char *s = (const unsigned char *)src;
	unsigned int i;

	for (i = 0; i < n; i++)
		d[i] = s[i];

	return (dest);
}
/**
 *_realloc - reallocates a memory block using malloc and free.
 *@ptr: pointer to the memory previously allocated
 *@old_size: size in bytes of the allocated space for ptr
 *@new_size: new size in bytes of the new memory block
 *
 *Return: pointer to new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	/*Create a new memory block*/
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/*copy old memory block's content to new memory block*/
	if (new_size > old_size)
		new_ptr = _memcpy(new_ptr, ptr, old_size);
	else
		new_ptr = _memcpy(new_ptr, ptr, new_size);

	/*free old memory block*/
	free(ptr);

	return (new_ptr);
}

/**
 * print_error - prints an error message to STDERR
 * @name: name the program
 * @status: error status
 * @input: input string
 * @desc: message description
 *
 */
void print_error(char *name, int status, char *input, char *desc)
{
	(void)status;

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "1: ", 3);
	write(STDERR_FILENO, input, _strlen(input));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, desc, _strlen(desc));
	write(STDERR_FILENO, "\n", 1);
}
