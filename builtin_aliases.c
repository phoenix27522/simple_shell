#include "shell.h"

static Alias *alias_list;

/**
 * getalias - get alias value
 * returns original argument if not found
 * @name: name of alias
 * Return: original argument if not found, otherwise value
 */
Alias *_getalias(const char *name)
{
	Alias *alias = alias_list;

	while (alias != NULL && _strcmp(alias->name, name) != 0)
		alias = alias->next;
	return (alias);
}
/**
 * _setalias - set alias to value
 * @name: name of alias
 * @value: set alias to
 * Return: 0 upon success
 */
int _setalias(const char *name, const char *value)
{
	Alias *new_alias;
	Alias *alias;

	alias = _getalias(name);

	if (alias != NULL)
	{
		free(alias->value);
		alias->value = _strdup(value);
		if (alias->value == NULL)
			return (-1);
	}
	else
	{/*creat new alias*/
		new_alias = malloc(sizeof(Alias));
		if (new_alias == NULL)
			return (-1);
		new_alias->name = _strdup(name);
		new_alias->value = _strdup(value);
		if (new_alias->name == NULL || new_alias->value == NULL)
		{
			free(new_alias->name);
			free(new_alias->value);
			free(new_alias);
			return (-1);
		}
		new_alias->next = alias_list;
		alias_list = new_alias;
	}
	return (0);
}
/**
 * _unsetalias - unset alias
 * @name: value to unset
 *
 * Return: 0 if sucess
 */
int _unsetalias(const char *name)
{
	Alias *prev = NULL;
	Alias *current = alias_list;

	while (current != NULL && strcmp(current->name, name) != 0)
	{
		prev = current;
		current = current->next;
	}
	if (current == NULL)
	{
		if (prev != NULL)
			prev->next = current->next;
		else
			alias_list = current->next;

		free(current->name);
		free(current->value);
		free(current);
	}
	return (0);
}
/**
 * print_alias -prints all the aliases
 *
 */
void print_alias(void)
{
	Alias *alias = alias_list;

	while (alias != NULL)
	{
		_puts(alias->name);
		_puts("=");
		_puts(alias->value);
		_puts("\n");
		alias = alias->next;
	}
}
/**
 * shell_alias - declaring shorthand for commands
 * @commands: that will be acceptes as arguments
 * must be tokenaized using = as delimeter
 *
 * Return: 0 on secusess
 */
int shell_alias(char **commands)
{
	int i;
	char *name, *value;

	if (commands[1] == NULL)
	{
		print_alias();
		return (0);
	}

	for (i = 1; commands[i] != NULL; i++)
	{
		name = _strtok(commands[i], "=");
		value = _strtok(NULL, "=");

		if (value != NULL)
			_setalias(name, value);
		else
		{
			Alias *alias = _getalias(name);

			if (alias != NULL)
			{
				_puts(alias->name);
				_puts("=");
				_puts(alias->value);
				_puts("\n");
			}
			else
			{
				_puts("alias: ");
				_puts(name);
				_puts(" not found\n");
			}
		}
	}
	return (0);
}
