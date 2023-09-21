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

	while (*saveptr != '\0' && _strchr(delim, *saveptr) != NULL)
		saveptr++;

	token_start = saveptr;
	if (*token_start == '\0')
		return (NULL);

	while (*saveptr != '\0' && !(_strchr(delim, *saveptr)))
		saveptr++;

	if (*saveptr != '\0')
	{
		*saveptr = '\0';
		saveptr++;
	}

	return (token_start);
}
