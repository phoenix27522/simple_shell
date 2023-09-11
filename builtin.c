#include "shell.h"
/**
 * shell_exit -exits from shell
 * @argv: unused
 *
 * Return: nothing it will not reach it will exit
 */
int shell_exit(char **argv)
{
	(void)argv;

	exit(0);
}
/**
 * shell_env - print current enviroment
 * @argv: accepts arguments
 *
 * Return: int
 *
 */
int shell_env(char **argv)
{
	int i = 0;
	char **env = environ;

	 (void)argv;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
