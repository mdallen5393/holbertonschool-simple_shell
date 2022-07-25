#include "main.h"

/*
int main(int ac, char **av, char **env)
{
	printf("%p\n", environ[0]);
	printf("%p\n", env[0]);
	printf("%s\n", _getenv("PATH"));
	printf("%s\n", _getenv("PWD"));
	return (0);
}
*/

void printenv(void)
{
	unsigned int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

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

int _setenv(const char *name, const char *value, int overwrite)
{
	char *nameCpy = _strdup(name);
	char *valueCpy = _strdup(value);
	int i, len = 0;
	int loc = envloc(name);
	char **new_environ;
	
	nameCpy = strcpycat(nameCpy, "=");
	nameCpy = strcpycat(nameCpy, valueCpy);
	
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
		return (-1);

	for (i = 0; i < len; i++)
		new_environ[i] = environ[i];

	new_environ[i] = nameCpy;
	new_environ[i + 1] = NULL;

	free(environ);
	environ = new_environ;

	return (0);
}

int _unsetenv(const char *name)
{
	char *nameCpy = _strdup(name);
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
		environ = new_environ;
	}

	return (0);
}
