#include "main.h"

int main(void)
{
	char *buffer = NULL;
	char **command;
	size_t bufsize = 0;

	while(1)
	{
		printf("($) ");

		if (getline(&buffer, &bufsize, stdin) == 1)
			continue;
		
		if (strcmp(buffer, "exit\n") == 0)
			break;
		else
		{
			command = make_av(buffer);
			if (execute(command) == -1)
				break;
		}
	}
	
	free(buffer);
	free(av);

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
		{
			perror("Error: ");
			return (-1);
		}
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
	
	if (argument[0] != '/' && argument[0] != '.')//FIXME: remake buffer
		argument = _strdup(_which(argument));
	
	av[0] = argument;
	
	i = 1;
	while (argument != NULL)
	{
		argument = strtok(NULL, " \n");
		av[i] = argument;
		i++;
	}

	av[i] = NULL;
	print_array(av); //TESTING
	return (av);
}
