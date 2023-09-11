#include "shell.h"
/**
 *  execute_builtin - search for match and execute the associate func
 * @argv: accepts agruments
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 **/
int execute_builtin(char **argv)
{
	int i;
	built list[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}

	};

	for (i = 0; list[i].built != NULL; i++)
	{
		if (_strcmp(list[i].built, argv[0]) == 0)
			return (list[i].func(argv));
	}
	return (-1);
}
