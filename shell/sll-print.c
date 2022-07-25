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
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", _strlen(temp->str), temp->str);

		num++;
		temp = temp->next;
	}

	return (num);
}
