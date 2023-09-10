#include "shell.h"
/**
 * run_cmd - Execute a command with arguments
 * @args: An array of strings representing the command and its arguments.
 *
 * a func that forks a new process and executes the
 * specified cmd with its args in the child process & the parent waits
 * for the child process to complete 
 */
void run_cmd(char **args)
{
	pid_t pid;
	char *path;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		/*child*/
		path = ;
		if(path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		/* to be replaced by our owen */

		strcpy(path, "/usr/bin/");
		strcat(path, args[0]);

		execve(path, args, NULL);
		perror("execve");

		free(path);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
char search_cmd(char *args, char *cmd, char *path)
{
	int i = 0;
	int position = 0;
	char *newpath;

	if (!path)/* Return NULL if 'path' is not provided*/
		return (NULL);
	if (_strstr(cmd, "./"))/* Return NULL if 'path' is not provided*/
	{
		if (is_cmd(cmd))/*Check if 'cmd' is a valid command*/
			return (cmd);
	}
	while (1)
	{
		if (!path[i] || path[i] == ':')/*Check for end of 'path' or a ':' character*/
		{
			path = _strdup(path, position, i);/*duplicate 'path' into 'newpath'*/
			if (!*newpath)
				_strcat(newpath, cmd);/*Copy 'cmd' into 'newpath'*/
			else
			{
				_strcat(newpath, "/");
				_strcat(newpath, cmd);
			}
			if (is_cmd(args, newpath))/*Check if 'newpath' is a valid command*/
				return (newpath);
			       	(path[i])
				break;
			position= i;/*Update the 'position' variable*/
		}
		i++;/*Increment 'i' to iterate through 'path'*/
	}
	return (NULL);
}
/**
 * is_cmd - determines if a file is an executable command
 * @path: path to the file
 *
 * Return: succes 0 otherwise -1;
 */
int is_cmd(char *path)
{
	struct stat new;

	if (stat(full_path, &new) != -1)
	{
		if (S_ISDIR(new.st_mode) ||  access(full_path, X_OK))
		{
			return (-1);
		}
		return (0);
	}
}
