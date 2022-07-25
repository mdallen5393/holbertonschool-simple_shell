#include "main.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the head of the linked list
 * @str: data to be placed in new node
 * Return: pointer to list
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *newNode;

	newNode = malloc(sizeof(list_t));

	if (!newNode)
	{
		free(newNode);
		return (NULL);
	}

	newNode->next = *head;
	*head = newNode;
	(*head)->str = _strdup(str);
	(*head)->next = newNode->next;

	return (*head);
}
