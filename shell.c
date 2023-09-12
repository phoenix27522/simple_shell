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
 */
void execute_command(char **commands, char *name)
{
	pid_t pid;
	char *path, *command;
	int status, get = 0;

	path = _getenv("PATH");

	get = execute_builtin(commands);

	if (get == 0)
		return;
	command = find_command(path, commands[0]);
	if (path == NULL || command == NULL)
	{
		perror(name);
		return;
	}
	pid = fork();
	if (pid < 0)
	{
		free(command);
		perror(name);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		char *envp[] = {NULL};

		if (execve(command, commands, envp) == -1)
		{
			perror(name);
			exit(EXIT_FAILURE);
		}
		free(command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
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
	unsigned int i, j, count = 0;

	if (input_cpy == NULL)
		exit(EXIT_FAILURE);
	token = strtok(input_cpy, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	tokens = malloc(sizeof(char *) * (count + 1));
	free(input_cpy);
	if (tokens == NULL)
		exit(EXIT_FAILURE);
	input_cpy = _strdup(input);
	token = strtok(input_cpy, delim);
	for (i = 0; i < count; i++)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free(input_cpy);
			free_commands(tokens);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
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

	/* if full_path to cmd is given*/
	if (access(command, X_OK) == 0)
		return (command);
	path_copy = _strdup(path);
	paths = parse_input(path_copy, ":");
	free(path_copy);
	while (paths[i] != NULL)
	{
		char *path1 = str_concat(paths[i], "/");
		char *full_path = str_concat(path1, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path1);
			free_commands(paths);
			return (full_path);
		}
		free(path1);
		free(full_path);
		full_path = NULL;
		path1 = NULL;
		i++;
	}
	free_commands(paths);
	return (NULL);
}
