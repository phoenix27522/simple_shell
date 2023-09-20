#include "shell.h"
/**
 * shell_exit -exits from shell
 * @commands: accepts argument
 * @stat: command exit status
 *
 * Return: nothing it will not reach it will exit
 */
int shell_exit(char **commands, int stat)
{
	int status, i;

	if (commands[1] != NULL)
	{
		for (i = 0; commands[1][i] != '\0'; i++)
		{
			if (!_isdigit(commands[1][i]))
			{
				_puts("Illegal number: ");
				_puts(commands[1]);
				_puts("\n");
				free_commands(commands);
				exit(1);
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
	exit(stat);
}
/**
 * shell_env - print current enviroment
 * @commands: accepts arguments
 * @stat: command exit status
 *
 * Return: int
 *
 */
int shell_env(char **commands, int stat)
{
	int i = 0;
	char **env = environ;
	(void)commands;
	(void)stat;


	while (env[i])
	{
		_puts(env[i]);
		_puts("\n");
		i++;
	}
	return (0);
}
