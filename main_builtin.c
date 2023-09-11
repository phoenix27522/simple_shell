#include "shell.h"
/**
 * execute_builtin - search for match and execute the associate func
 * @argv: accepts agruments
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 **/
int execute_builtin(char *argv)
{
	int i;
	built list[] = {
		{"exit", shell_exit},
		{NULL, NULL}

	};

	for (i = 0; list[i].built != NULL; i++)
	{
		if (_strncmp(list[i].built, argv, _strlen(list[i].built)) == 0)
			return (list[i].func(argv));
	}
	return (-1);
}
