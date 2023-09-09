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
		path = (char *)malloc(sizeof(char) * BUFF_SIZE);
		if(path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		/* to be replaced by our owen */

		strcpy(path, "/bin/");
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
