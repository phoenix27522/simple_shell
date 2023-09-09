#include "shell.h"

/**
 * main - Entry Point
 *
 * Return: 0 (Sucess)
 */
int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	int i;
	char **tokens;

	while (1)
	{
		display_prompt();
		/* Read User Input*/
		fflush(stdout);

		if (getline(&command, &bufsize, stdin) == -1)
		{
			_puts("\n");
			free(command);
			break;
		}

		command = _strn(command);


	}

	return (EXIT_SUCCESS);
}
