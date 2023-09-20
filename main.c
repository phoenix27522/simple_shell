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
	char *input = NULL;
	size_t bufsize = 0;
	char **commands;
	(void)argc;

	while (1)
	{
		display_prompt();
		/* Read User Input*/

		if (getline(&input, &bufsize, stdin) == -1)
		{
			_puts("\n");
			free(input);
			break;
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
	}

	return (EXIT_SUCCESS);
}
