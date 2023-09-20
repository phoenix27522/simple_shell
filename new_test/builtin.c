#include "shell.h"
#include <stdbool.h>
/**
 * shell_exit -exits from shell
 * @commands: accepts argument
 *
 * Return: nothing it will not reach it will exit
 */
int shell_exit(char **commands)
{
	int status = 0;
	int i = 0;
	if (commands[1] != NULL)
	{
		for (; commands[1][i] != '\0'; i++)
		{
			if (!_isdigit(commands[1][i]))
			{
				write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
				write(STDERR_FILENO, commands[1], strlen(commands[1]));
				write(STDERR_FILENO, "\n", 1);
				free_commands(commands);
				exit(2);
			}
		}
		status = _atoi(commands[1]);
		if (status != 0)
		{
			free_commands(commands);
			exit(status);
		}
		else
		{
			_puts("Invalid status code: ");
			_puts(commands[1]);
			_puts("\n");
		}
	}
	free_commands(commands);
	exit(status);
}
/**
 * shell_env - print current enviroment
 * @commands: accepts arguments
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
