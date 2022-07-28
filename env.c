#include "main.h"

/*
 * int main(int ac, char **av, char **env)
 * {
 *	 printf("%p\n", environ[0]);
 *	 printf("%p\n", env[0]);
 *	 printf("%s\n", _getenv("PATH"));
 *	 printf("%s\n", _getenv("PWD"));
 *	 printenv();
 *	 return (0);
 * }
 */

/**
  * printenv - displays current environment
  *
  */

void printenv(void)
{
	unsigned int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}

/**
  * _getenv - gets an environment variable
  * @name: variable to search in the environment
  *
  * Return: pointer to the value in the environment, NULL if there is no match
  */
char *_getenv(const char *name)
{
	unsigned int i = 0;
	int diff;
	int varlen = _strlen(name);

	while (environ[i])
	{
		diff = _strncmp(environ[i], name, varlen);
		if (diff == 0)
			return (environ[i] + varlen + 1);
		i++;
	}
	return (NULL);
}

/**
  * envloc - locates a variable in the environment
  * @name: variable to be located in the environment
  *
  * Return: location in environment array on success, -1 on error
  */
int envloc(const char *name)
{
	unsigned int i = 0;
	int diff;
	int varlen = _strlen(name);

	while (environ[i])
	{
		diff = _strncmp(environ[i], name, varlen);
		if (diff == 0)
			return (i);
		i++;
	}
	return (-1);
}

/**
  * _setenv - changes or adds an environment variable
  * @name: name of variable to be changed/added
  * @value: value of newly set variable
  * @overwrite: previous value of newly set variable
  *
  * Return: 0 on success, -1 on error
  */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *nameCpy = _strdup(name), *valueCpy = _strdup(value);
	int i, len = 0, loc = envloc(name);
	char **new_environ;
	char *temp = strcpycat(nameCpy, "=");

	free(nameCpy);
	nameCpy = strcpycat(temp, valueCpy);
	free(valueCpy);
	free(temp);

	if (loc != -1)
	{
		if (overwrite == 0)
			return (0);
		environ[loc] = nameCpy;
		return (0);
	}

	while (environ[len])
		len++;

	new_environ = malloc(sizeof(*new_environ) * (len + 2));
	if (!new_environ)
	{
		free(nameCpy);
		return (-1);
	}

	for (i = 0; i < len; i++)
		new_environ[i] = environ[i];

	new_environ[i] = nameCpy;
	free(nameCpy);
	new_environ[i + 1] = NULL;

	free(environ);
	free_array(environ);
	environ = new_environ;

	return (0);
}

/**
  * _unsetenv - deletes the variable name from the environment
  * @name: name of variable to be deleted
  *
  * Return: 0 on success, -1 on error
  */
int _unsetenv(const char *name)
{
	int loc = envloc(name);
	int i, j, len = 0;
	char **new_environ;

	while (environ[len])
		len++;

	if (loc != -1)
	{
		free(environ[loc]);
		new_environ = malloc(sizeof(*new_environ) * len);

		j = 0;
		for (i = 0; i < len; i++)
		{
			if (i != loc)
			{
				new_environ[i] = environ[j];
				j++;
			}
		}
		new_environ[i] = NULL;

		free(environ);
		free_array(environ);
		environ = new_environ;
	}

	return (0);
}
