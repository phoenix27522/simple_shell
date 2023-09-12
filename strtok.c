#include "shell.h"
/**
 * _strtok - Tokenizes a string using specified delimiters
 * @line: Pointer to the input string
 * @delim: String containing delimiter characters
 *
 * Return: A pointer to the next token or NULL if no more tokens are found
 */
char *_strtok(char *line, char *delim)
{
	static char *saveptr;
	char *token_start;

	if (line != NULL)
		saveptr = line;
	else if (saveptr == NULL || *saveptr == '\0')
		return (NULL);

	while (*saveptr != '\0' && _strchr(delim, *saveptr))
		saveptr++;

	token_start = saveptr;

	while (*saveptr != '\0' && !(_strchr(delim, *saveptr)))
		saveptr++;

	if (*saveptr != '\0')
	{
		*saveptr = '\0';
		saveptr++;
	}

	return (token_start);
}
