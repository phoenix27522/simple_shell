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
	exit(stat);
}
/**
 * shell_env - print current enviroment
 * @commands: accepts arguments
 * @stat: command exit status
 *
 * Return: int
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
/**
 * shell_cd - changes the current directory of the process
 * @commands: accepts argument
 * @stat: status
 * Return: 0 on success, -1 on failure
 */
int shell_cd(char **commands, int stat)
{
	char *dir = NULL, store_dir[MAX_SIZE], *current_dir, **env = environ;
	int check_chdir = 0;

	(void)stat;

	current_dir = getcwd(store_dir, MAX_SIZE);
	if (!current_dir)
	{
		perror("can't cd to");
		exit(127);
	}
	if (!commands[1])
	{	dir = _getenv("HOME");
		if (!dir)
			dir = _getenv("PWD");
		else
			check_chdir = chdir(dir);
	}
	else if (_strcmp(commands[1], "-") == 0)
	{	dir = _getenv("OLDPWD");
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
	{	_setenv("OLDPWD", current_dir, env);
		_setenv("PWD", getcwd(store_dir, sizeof(store_dir)), env);
		return (0);
	}
	return (-1);

}
