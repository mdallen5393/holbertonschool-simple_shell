#include "main.h"

char *_which(char *exec)
{
	char *executable;
	char *path, *curr;
	list_t *path_list;
	char *final_path;
	struct stat st;
	
	executable = strcpycat("/", exec);
	path = _getenv("PATH");
	path_list = make_env(path);
	
	while (path_list)
	{
		curr = strcpycat(path_list->str, executable);
		if (stat(curr, &st) == 0)
			return (curr);
		path_list = path_list->next;
	}

	return (NULL);
}


list_t *make_env(char *str)
{
	list_t *env = NULL;

	char *buffer = strdup(str);
	char *nodeStr;
	int i = 0, numNodes = 0;
	
	nodeStr = strtok(buffer, ":");
	add_node_end(&env, nodeStr);

	while (nodeStr != NULL)
	{
		nodeStr = strtok(NULL, ":");
		add_node_end(&env, nodeStr);
		i++;
	}
	
	return (env);
}

void print_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
	if (array[i] == NULL)
		printf("NULL\n");
}
