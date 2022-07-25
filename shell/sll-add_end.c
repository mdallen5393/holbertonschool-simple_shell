#include "main.h"

/**
 * add_node_end - add new node at the end of a list_t list.
 * @head: pointer to front of list
 * @str: string to add to new node
 * Return: address of new element, or NULL upon failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newNode = malloc(sizeof(list_t));
	list_t *temp = *head;
	if (!newNode)
		return (NULL);

	newNode->str = _strdup(str);
	newNode->next = NULL;
	
	if (*head == NULL)
		*head = newNode;
	else
	{
		while (temp->next)
			temp = temp->next;
		
		temp->next = newNode;
	}

	return (newNode);
}
