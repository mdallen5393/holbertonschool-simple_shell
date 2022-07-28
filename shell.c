#include "main.h"



int main(int argc, char **argv, char **env)
{
	if (run(isatty(STDIN_FILENO)) == 2)
	{
		perror(argv[0]);
		return (2);
	}

	return (0);
}

int run(int isInteractive)
{	
	char *buffer = NULL;
	char **command;
	size_t bufsize = 0;
	int line;
	 
	if (isInteractive != 1) /* non-interactive */
	{
		while ((line = getline(&buffer, &bufsize, stdin)) != -1)
		{
			if (strcmp(buffer, "exit\n") == 0)
			{	
				free(buffer);
				break;
			}
			else if (strcmp(buffer, "env\n") == 0)
			{
				free(buffer);
				printenv();
				continue;
			}
			else
			{
				command = make_av(buffer);
				if (execute(command) == 2)
					return (2);
			}
			free(buffer);
			free_array(command);
		}
	}
	else /* interactive */
	{
		while (1)
		{
			_puts("($) ");

			line = getline(&buffer, &bufsize, stdin);
			if (strcmp(buffer, "\n") == 0)
			{
				free(buffer);
				buffer = NULL;
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
				free(buffer);
				buffer = NULL;
				printenv();
				continue;
			}	
			
			command = make_av(buffer); /* TODO: */
			
			if (execute(command) == 2)
			{
				// free_array(command);
				free(buffer);
				buffer = NULL;
				free(command);
				continue;
			}
			free(buffer);
			buffer = NULL;
			free(command);

			/* free_array(command); */ /* remove */
		}
		free(buffer);
	}

	return (0);
}

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


char **make_av(char *str)
{
	char *buffer = str; /* FIXME: remove buffer; replace with str */
	char *argument, *arg0;
	char prev = '0';
	int i = 0, numArgs = 0;
	struct stat st;

	while (buffer[i])
	{
		if (buffer[i] == ' ')
			i++;
		else
		{
			numArgs++;
			while (buffer[i] && buffer[i] != ' ')
				i++;
		}
	}
	
	av = malloc(sizeof(*av) * (numArgs + 1 /* + 1 */));
	if (!av)
	{
		perror("Error malloc'ing for av\n");
		exit(98);
	}
	
	argument = strtok(buffer, " \n");
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

	/* free(buffer); */
	/* print_array(av); */ /* TESTING */
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