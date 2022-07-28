#include "main.h"

/**
 * run_nonint - run shell non-interactively
 * @shell_name: name of executable shell
 *
 * Return: 0 on success, 2 on unrecognized command
 */
int run_nonint(char *shell_name)
{
	char **command;
	char *buffer = NULL;
	size_t bufsize = 0;
	int line;

	while ((line = getline(&buffer, &bufsize, stdin)) != -1)
	{
		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			break;
		}
		if (strcmp(buffer, "env\n") == 0)
		{
			free(buffer);
			printenv();
			continue;
		}
		command = make_av(buffer);
		if (execute(command) == 2)
		{
			_puts(shell_name);
			_puts(": No such file or directory\n");
		}
		free(buffer);
		free_array(command);
	}
	return (0);
}

/**
 * run_int - run shell interactively
 * @shell_name: name of executable shell
 *
 * Return: 0 on success, 2 on unrecognized command
 */
int run_int(char *shell_name)
{
	char **command, *buffer = NULL;
	size_t bufsize = 0;
	int line;

	while (1)
	{
		_puts("($) ");
		line = getline(&buffer, &bufsize, stdin);
		if (strcmp(buffer, "\n") == 0)
		{
			free(buffer), buffer = NULL;
			continue;
		}
		if (line == -1)
		{
			_putchar('\n');
			break;
		}
		if (strcmp(buffer, "exit\n") == 0)
			break;
		if (strcmp(buffer, "env\n") == 0)
		{
			free(buffer), buffer = NULL;
			printenv();
			continue;
		}
		command = make_av(buffer); /* TODO: */
		if (execute(command) == 2)
		{ /* free_array(command); */
			free(buffer), buffer = NULL, free(command);
			_puts(shell_name), _puts(": No such file or directory\n");
			continue;
		}
		free(buffer), buffer = NULL, free(command); /* free_array(command); */
	}
	free(buffer);
	return (0);
}
