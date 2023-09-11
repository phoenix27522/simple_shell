#include "shell.h"

/**
 * display_prompt - displays a prompt
 *
 */
void display_prompt(void)
{
	_puts(":) ");
}
/**
 * execute_command - executes a command
 * @commands: pointer to arrays of strings
 * of a command and its arguments and options
 * @name: name of the program
 *
 */
void execute_command(char **commands, char *name)
{
	pid_t pid;
	char *path, *command;
	int get = 0;

	path = _getenv("PATH");

	get = execute_builtin(commands[0]);
	if (get == -1)
		command = find_command(path, commands[0]);

	if (path == NULL || command == NULL)
	{
		perror(name);
		return;
	}
	pid = fork();

	if (pid < 0)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		char *envp[] = {NULL};

		if (execve(command, commands, envp) == -1)
		{
			free(commands);
			perror(name);
			exit(EXIT_FAILURE);
		}
		free(commands);
		exit(EXIT_SUCCESS);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
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
	char **tokens;
	char *token, *input_cpy = _strdup(input);
	unsigned int i, count = 0;

	if (input_cpy == NULL)
	{
		free(input_cpy);
		exit(EXIT_FAILURE);
	}
	token = strtok(input_cpy, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	tokens = malloc(sizeof(char *) * count + 1);
	if (tokens == NULL)
	{
		free(input_cpy);
		exit(EXIT_FAILURE);
	}
	input_cpy = _strdup(input);
	token = strtok(input_cpy, delim);
	for (i = 0; i < count; i++)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free(input_cpy);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	free(input_cpy);

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
	char *path_copy = _strdup(path);
	char **paths = parse_input(path_copy, ":");
	unsigned int i = 0;

	while (paths[i] != NULL)
	{
		char *path1 = str_concat(paths[i], "/");
		char *full_path = str_concat(path1, command);

		if (access(command, X_OK) == 0)
		{
			free(path_copy);
			free(path1);
			return (command);
		}
		else if (access(full_path, X_OK) == 0)
		{
			free(path1);
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free(path_copy);
	free(paths);
	return (NULL);
}
