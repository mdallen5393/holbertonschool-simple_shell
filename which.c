#include "main.h"

char *_which(char *exec)
{
	char *executable;
	char *path, *curr;
	list_t *path_list, *temp;
	char *final_path;
	struct stat st;
	
	executable = strcpycat("/", exec);
	path = _getenv("PATH");
	path_list = make_env(path);
	temp = path_list;

	while (temp)
	{
		curr = strcpycat(temp->str, executable);
		if (stat(curr, &st) == 0)
		{
			free(executable);
			free_list(path_list);
			return (curr);
		}
		free(curr);
		temp = temp->next;
	}

	free(executable);
	free_list(path_list);

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

	free(buffer);
	
	return (env);
}