#include "shell.h"
/**
 * shell_exit -exits from shell
 * @argv: unused
 *
 * Return: nothing it will not reach it will exit
 */
int shell_exit(char **commands)
{
	free_commands(commands);
	exit(0);
}
/**
 * shell_env - print current enviroment
 * @argv: accepts arguments
 *
 * Return: int
 *
 */
int shell_env(char **commands)
{
	int i = 0;
	char **env = environ;
	(void)commands;


	while (env[i])
	{
		_puts(env[i]);
		_puts("\n");
		i++;
	}
	return (0);
}
