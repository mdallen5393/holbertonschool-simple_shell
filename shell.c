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
	int num;
	 
	if (isInteractive != 1)
	{
		while ((num = getline(&buffer, &bufsize, stdin)) != -1)
		{
			if (strcmp(buffer, "exit\n") == 0)
			{	
				break;
				free(buffer);
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
			free (buffer);
			free_array(command);
		}
	}
	else
	{
		while (1)
		{
			_puts("($) ");

			if (getline(&buffer, &bufsize, stdin) == 1)
				continue;
			
			if (strcmp(buffer, "exit\n") == 0)
			{	
				break;
				free(buffer);
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
					exit(2);
			}
			free(buffer);
			free_array(command);
		}
	}

	return (0);
}

int execute(char **command)
{
	pid_t is_kid;
	
	is_kid = fork();

	if (is_kid != 0)
	{
		wait(NULL);
		return(0);
	}
	if (is_kid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
			return (2);
	}

	return (0);
}


char **make_av(char *str)
{
	char *buffer = strdup(str);
	char *argument;
	char prev = '0';
	int i = 0, numArgs = 0;

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
	
	av = malloc(sizeof(*av) * (numArgs + 1));
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

	if (av[0][0] != '/' && av[0][0] != '.')
		av[0] = _strdup(_which(av[0]));

	free(buffer);

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
