#include "shell.h"

/**
 * main - Entry Point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (Sucess)
 */
int main(int argc, char *argv[])
{
	char *input = NULL, **commands;
	size_t bufsize = 0;
	int mode;
	(void)argc;

	/*mode = isatty(STDIN_FILENO);*/
	while (1)
	{
		mode = isatty(STDIN_FILENO);
		if (mode == INT_MODE)
			display_prompt();
		if (getline(&input, &bufsize, stdin) == -1)
		{	free(input);
			if (mode == INT_MODE)
			{
				_puts("\n");
				break;
			}
			else
				exit(0);
		}
		input[_strlen(input) - 1] = '\0';
		if (input[0] != '\0')
		{
			commands = parse_input(input, " ");
			free(input);
			input = NULL;
			if (commands != NULL)
			{
				execute_command(commands, argv[0]);
				free_commands(commands);
			}
			commands = NULL;
			continue;
		}
		free(input);
		input = NULL;
		if (mode != INT_MODE)
			break;
	}
	return (EXIT_SUCCESS);
}
