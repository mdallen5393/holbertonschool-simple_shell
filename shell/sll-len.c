#include "main.h"

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
