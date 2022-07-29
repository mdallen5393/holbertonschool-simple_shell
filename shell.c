#include "main.h"

/**
 * main - runs simple shell (determines whether interactive or not)
 * @argc: integer argument count
 * @argv: argument vector
 * @env: environment vector
 *
 * Return: 0 on success, 2 for unrecognized command
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)env;

	if (run(isatty(STDIN_FILENO), argv[0]) == 2)
	{
		perror(argv[0]);
		return (2);
	}

	return (0);
}

/**
 * run - runs simple shell in interactive or non-interactive mode
 * @isInteractive: value returned from function isatty
 * @shell_name: name of version of shell that is running
 * Return: 0 on success; 2 with unrecognized command
 */
int run(int isInteractive, char *shell_name)
{
	if (isInteractive != 1) /* non-interactive */
	{
		if (run_nonint(shell_name) == 2)
			return (2);
	}
	else /* interactive */
		run_int(shell_name);

	return (0);
}

/**
 * execute - uses fork to create child process, which execves
 * @command: NULL-terminated array of strings containing command and args
 *
 * Return: doesn't return from child; parent: 0 on success, 2 on failure
 */
int execute(char **command)
{
	pid_t is_kid;

	is_kid = fork();

	if (is_kid != 0)
		wait(NULL);

	if (is_kid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
			return (2);
	}

	return (0);
}

/**
 * make_av - creates a NULL-terminated array of strings for use in execve
 * @str: string containing name of function and arguments
 *
 * Return: pointer to array of strings
 */
char **make_av(char *str)
{
	char *argument, *arg0;
	int i = 0, numArgs = 0;
	struct stat st;

	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			numArgs++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	av = malloc(sizeof(*av) * (numArgs + 1 /* + 1 */));
	if (!av)
	{
		perror("Error malloc'ing for av\n");
		exit(98);
	}
	argument = strtok(str, " \n");
	av[0] = argument;
	i = 1;
	while (argument != NULL)
	{
		argument = strtok(NULL, " \n");
		av[i] = argument;
		i++;
	}
	if (stat(av[0], &st) != 0)
	{
		arg0 = _which(av[0]);
		av[0] = _strdup(arg0);
		free(arg0);
	}
	/* free(str); */
	return (av);
}

/**
 * free_array - frees array of strings
 * @array: pointer to 2D array of strings
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}

	free(array);
}
