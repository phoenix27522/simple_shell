#include "shell.h"
/**
 * shell_setenv - set the enviroment
 * @commands: accepts arguments
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int shell_setenv(char **commands)
{
	char **env = environ;

	if (commands[1] == NULL || commands[2] == NULL)
	{
		_puts("Usage: setenv VARIABLE VALUE");
		return (0);
	}

	if (commands[3] != NULL)
	{
		perror("setenv");
		return (0);
	}

	if (_setenv(commands[1], commands[2], env) == 0)
		_puts("Environment variable set successfully\n");
	else
		_puts("Error setting environment variable\n");

	return (0);
}
/**
 * _setenv - overwrite the value of the environment variable
 * or create it if it does not exist.
 * @name: name of the environment variable to set
 * @value: new value
 * @env: pointer to the environment variables
 * Return: 1 if the parameters are NULL.
 * 2 if there is an error, or 0 if success.
 */
int _setenv(char *name, char *value, char **env)
{
	int overwrite = 0, i = 0, new_env_len;
	char *new_env_var = NULL;

	if (name == NULL || value == NULL || env == NULL)
		return (-1);

	for (; env[i]; i++)
	{
		if (_strncmp(name, env[i], _strlen(name)) == 0
				&& env[i][_strlen(name)] == '=')
		{
			overwrite = 1;
			if (value == NULL)
			{
				free(env[i]);
				env[i] = NULL;
			}
			else
			{
				new_env_var = (char *)malloc(_strlen(name) + _strlen(value) + 2);
				if (new_env_var == NULL)
				{
					perror("malloc");
					free(new_env_var);
					return (-2);
				}
				_memset(new_env_var, 0, _strlen(name) + _strlen(value) + 2);
				_strcpy(new_env_var, name);
				_strcat(new_env_var, "=");
				_strcat(new_env_var, value);
				env[i] = new_env_var;
			}
			break;
		}
	}
	if (!overwrite && value != NULL)/*new variable*/
	{
		new_env_len = _strlen(name) + _strlen(value) + 2;
		new_env_var = (char *)malloc(new_env_len);
		if (new_env_var == NULL)
		{
			perror("malloc");
			return (-2);
		}
		_memset(new_env_var, 0, new_env_len);
		_strcpy(new_env_var, name);
		_strcat(new_env_var, "=");
		_strcat(new_env_var, value);

		while (env[i] != NULL)
			i++;
		free(env[i]);
		env[i] = new_env_var;
		env[i + 1] = NULL;
	}
	return (0);
}
/**
 * shell_unsetenv - unset the enviroment
 * @commands: accepts arguments
 * Return: 0 sucess, or other number if its declared in the arguments
 */
int shell_unsetenv(char **commands)
{
	char **env = environ;

	if (commands[1] == NULL)
	{
		_puts("Usage: unsetenv <variable>");
		return (0);
	}

	if (commands[2] != NULL)
	{
		return (0);
	}

	if (_unsetenv(commands[1], env) == 1)
	{
		_puts("Environment variable unset successfully\n");
		return (0);
	}
	else
	{
		_puts("Environment variable not found\n");
		return (1);
	}
}
/**
 * _unsetenv - unsets the enviroment
 * @name: name of the enviroment to unset
 * @env: points to our localenviroment
 *
 * Return: 1 on sucsses 0 if it failes on un seting the enviroment
 */
int _unsetenv(char *name, char **env)
{
	int i, j;

	if (name == NULL || env == NULL)
		return (-1);

	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(name, env[i], _strlen(name)) == 0
				&& env[i][_strlen(name)] == '=')
		{
			/*free(env[i]);*/

			for (j = i; env[j] != NULL; j++)
				env[j] = env[j + 1];

			return (1);

		}
	}
	return (0);
}
