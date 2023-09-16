#include "shell.h"
/**
 *  execute_builtin - search for match and execute the associate func
 * @commands: accepts agruments
 * Return: Returns the return of the function executed is there is a match,
 * otherwise returns -1.
 **/
int execute_builtin(char **commands)
{
	int i;
	built list[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{"setenv", shell_setenv},
		{"unsetenv", shell_unsetenv},
		{"cd", shell_cd},
		{NULL, NULL}

	};

	for (i = 0; list[i].built != NULL; i++)
	{
		if (_strcmp(list[i].built, commands[0]) == 0)
			return (list[i].func(commands));
	}
	return (-1);
}
