#include "shell.h"
/**
 * display_prompt - displays a prompt
 *
 */
void display_prompt(void)
{
	_puts("$ ");
	fflush(stdout);
}
/**
 * execute_command - executes a command
 * @commands: pointer to arrays of strings
 * of a command and its arguments and options
 * @name: name of the program
 * @envp: environnement variables pointer
 * @stat:exit status of child
 */
void execute_command(char **commands, char *name, char **envp, int *stat)
{
	pid_t pid;
	char *path, *command = NULL, *error = "not found";
	int status, get = 0;

	get = execute_builtin(commands, *stat);
	if (get == 0)
		return;
	path = _getenv("PATH");
	if (path == NULL || *path == '\0')
		command = _strdup(commands[0]);
	else
		command = find_command(path, commands[0]);
	if (command == NULL || ((path == NULL || *path == '\0') && *command != '/'))
	{	print_error(name, 1, commands[0], error);
		*stat = 127;
		free(command);
		return;
	}
	pid = fork();
	if (pid < 0)
	{	perror(name), free(command);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(command, commands, envp) == -1)
		{	print_error(name, 1, commands[0], error);
			free(command), free_commands(commands);
			exit(127);
		}
		free(command);
		free_commands(commands);
		exit(EXIT_SUCCESS);
	}
	else
	{	waitpid(pid, &status, 0);
		*stat = WEXITSTATUS(status);
		free(command);
	}
}

/**
 * parse_input - splits the input into tokens
 * @input: string
 * @delim: delimeter
 *
 * Return: pointer to array of strings
 */
char **parse_input(const char *input, char *delim)
{
	char **tokens = NULL;
	char *token, *input_cpy = _strdup(input);
	unsigned int i, count = 0;

	if (input_cpy == NULL)
		return (NULL);
	token = _strtok(input_cpy, delim);
	if (token == NULL)
	{
		free(input_cpy);
		return (NULL);
	}
	while (token != NULL)
	{
		count++;
		token = _strtok(NULL, delim);
	}
	tokens = malloc(sizeof(char *) * (count + 1));
	free(input_cpy);
	if (tokens == NULL)
		return (NULL);
	input_cpy = _strdup(input);
	token = _strtok(input_cpy, delim);
	for (i = 0; i < count; i++)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free(input_cpy);
			free_commands(tokens);
			return (NULL);
		}
		token = _strtok(NULL, delim);
	}
	free(input_cpy);
	tokens[i] = NULL;

	return (tokens);
}

/**
 * find_command - searches for the command in PATH
 * @path: PATH
 * @command: input
 * Return: path is found, NULL otherwise
 */
char *find_command(char *path, char *command)
{
	char *path_copy;
	char **paths;
	unsigned int i = 0;

	if (path[0] == '\0')
		return (NULL);
	/* if full_path to cmd is given*/
	if (access(command, X_OK) == 0)
		return (_strdup(command));
	path_copy = _strdup(path);
	paths = parse_input(path_copy, ":");
	free(path_copy);
	while (paths[i] != NULL)
	{
		char *path1 = str_concat(paths[i], "/");
		char *full_path = str_concat(path1, command);

		free(path1);
		if (access(full_path, X_OK) == 0)
		{
			free_commands(paths);
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
		path1 = NULL;
		i++;
	}
	free_commands(paths);
	return (NULL);
}
