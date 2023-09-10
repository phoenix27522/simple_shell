#include "shell.h"
extern char **environ;
/**
 * _getenv - gets the value of an environ variable
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(const char *path)
{
	int path_length;
	char **env;

	if (path == NULL || environ == NULL)
		return (NULL);

	path_length = _strlen(path);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(path, *env, path_length) == 0 && (*env)[path_length] == '=')
			return ((*env) + path_length + 1);
	}
	return (NULL);


}
