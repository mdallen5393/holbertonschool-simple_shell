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

/**
 * insert_node_at_index - insert a new node at a given position
 * @head: list passed in
 * @idx: index of the list where new node should be added
 * @str: string to be added into new node
 * Return: the address of the new node, or NULL upon failure.
 */
list_t *insert_node_at_index(list_t **head, unsigned int idx, char *str)
{
	list_t *temp = *head;
	list_t *newNode = malloc(sizeof(*newNode));
	unsigned int i = 0;

	if (!newNode)
		return (NULL);

	newNode->str = _strdup(str);

	if (idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	while (temp)
	{
		if (i == idx - 1)
			break;
		i++;
		temp = temp->next;
	}

	if (i < idx - 1)
		return (NULL);

	newNode->next = temp->next;
	temp->next = newNode;

	return (newNode);
}
