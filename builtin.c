#include "shell.h"
/**
 * shell_exit -exits from shell
 * @commands: unused
 *
 * Return: nothing it will not reach it will exit
 */
int shell_exit(char **commands)
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
	exit(0);
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
/**
 * shell_cd - changes the current directory of the process
 * @commands: accepts argument
 *
 * Return: 0 on success, -1 on failure
 */
int shell_cd(char **commands)
{
	char *dir = NULL, store_dir[MAX_SIZE], *current_dir, **env = environ;
	int check_chdir = 0;

	current_dir = getcwd(store_dir, MAX_SIZE);
	if (!current_dir)
	{
		perror("getcwd");
		return (-1);
	}
	if (!commands[1])
	{
		dir = _getenv("HOME");
		if (!dir)
			dir = _getenv("PWD");
		else
			check_chdir = chdir(dir);
	}
	else if (_strcmp(commands[1], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (!dir)
		{
			_puts(current_dir);
			_puts("\n");
			return (0);
		}
		_puts(dir);
		_puts("\n");
		check_chdir = chdir(dir);
	}
	else
		check_chdir = chdir(commands[1]);
	if (check_chdir != -1)
	{
		_setenv("OLDPWD", current_dir, env);
		_setenv("PWD", getcwd(store_dir, sizeof(store_dir)), env);
		return (0);
	}
	return (-1);

}
