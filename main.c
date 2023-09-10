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
		fflush(stdout);

		if (getline(&input, &bufsize, stdin) == -1)
		{
			_puts("\n");
			free(input);
			break;
		}

		input = _strn(input);
		commands = parse_input(input, " ");
		execute_command(commands, argv[0]);


	}

	return (EXIT_SUCCESS);
}