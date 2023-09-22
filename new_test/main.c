#include "shell.h"

/**
 * main - Entry Point
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variables vector
 *
 * Return: 0 (Sucess)
 */
int main(int argc, char *argv[], char **envp)
{
	char *input = NULL, **commands;
	size_t bufsize = 0;
	int mode, status = 0;
	(void)argc;

	mode = isatty(STDIN_FILENO);
	while (1)
	{
		if (mode == INT_MODE)
			display_prompt();
		if (getline(&input, &bufsize, stdin) == -1)
		{
			free(input);
			if (mode == INT_MODE)
				_puts("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (input[0] != '\0')
		{
			commands = parse_input(input, " ");
			free(input);
			input = NULL;
			if (commands != NULL)
			{
				execute_command(commands, argv[0], envp, &status);
				free_commands(commands);
			}
			commands = NULL;
			continue;
		}
		free(input);
		input = NULL;
	}
	if (mode != INT_MODE)
		exit(status);
	return (EXIT_SUCCESS);
}
