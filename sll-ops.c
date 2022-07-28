#include "main.h"

/**
 * print_list - prints all elements of a list_t list.
 * @h: linked list to print
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	int num = 0;
	const list_t *temp = h;

	while (temp)
	{
		if (!(temp->str))
		{
			/* printf("[%d] (nil)\n", i); */
			_putchar('[');
			_putint(num);
			_puts("] (nil)\n");
		}
		else
		{
			/* printf("[%d] %s\n", num, temp->str); */
			_putchar('[');
			_putint(num);
			_puts("] ");
			_puts(temp->str);
			_putchar('\n');
		}
		num++;
		temp = temp->next;
	}
	return (num);
}

/**
 * list_len - returns the number of elements in a linked list
 * @h: linked list to find length of
 * Return: number of elements in the list
 */
size_t list_len(const list_t *h)
{
	int num = 0;
	const list_t *temp = h;

	while (temp)
	{
		num++;
		temp = temp->next;
	}

	return (num);
}

/**
 * free_list - frees a list_t list.
 * @head: list to free
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}

/**
 * delete_node_at_index - delete node at index "index" of a "list_t"
 * @head: input list
 * @index: index of node to delete
 * Return: 1 upon success, -1 upon failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	unsigned int i = 0;
	list_t *temp = *head;
	list_t *node_to_delete;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		node_to_delete = *head;
		free(node_to_delete->str);
		*head = (*head)->next;
		free(node_to_delete);

		return (1);
	}

	while (temp && index != 0)
	{
		if (i == index - 1)
			break;
		temp = temp->next;
		i++;
	}

	if (!temp)
		return (-1);

	node_to_delete = temp->next;
	free(node_to_delete->str);
	temp->next = temp->next->next;
	free(node_to_delete);

	return (1);
}
