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
	int i;
	char **commands;
	char **command;
	(void)argc;

	while (1)
	{
		display_prompt();
		/* Read User Input*/

		if (_getline(&input, &bufsize, stdin) == -1)
		{
			_puts("\n");
			free(input);
			break;
		}

		input[_strlen(input) - 1] = '\0';

		if (input[0] != '\0')
		{
			/* handle command separator ; */
			commands = parse_input(input, ";");
			free(input);
			input = NULL;
			if (commands != NULL)
			{
				for (i = 0; commands[i] != NULL; i++)
				{
					command = parse_input(commands[i], " ");
					if (command != NULL)
					{
						execute_command(command, argv[0]);
						free_commands(command);
					}
					command = NULL;
				}
			}
			free_commands(commands);
			commands = NULL;
			continue;
		}

		free(input);
		input = NULL;
	}

	return (EXIT_SUCCESS);
}
