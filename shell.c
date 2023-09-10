#include "shell.h"

/**
 * display_prompt - displays a prompt
 *
 */
void display_prompt(void)
{
	_puts("simple_shell$ ");
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
	pid_t pid = fork();

	if (pid < 0)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		char *envp[] = {NULL};

		if (execve(commands[0], commands, envp) == -1)
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
