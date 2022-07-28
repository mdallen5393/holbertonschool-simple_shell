#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line, to stdout.
 * @str: string to print
 */
void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putint - prints an integer.
 * @n: integer to print.
 *
 * Return: -1 on failure of dipr (malloc), 0 otherwise.
 */
int _putint(int n)
{
	char *intStr = dipr(n);

	if (!intStr)
		return (-1);

	_puts(intStr);
	free(intStr);
	return (0);
}

/**
 * dipr - convert integer types to strings and returns pointer to string
 * @n: integer to convert to string
 *
 * Return: pointer to new string
 */
char *dipr(int n)
{
	int len, i, copy, input, end;
	char *numStr;

	input = n;
	copy = input;
	len = 1;

	if (input == INT_MIN)
		return ("-2147483648");

	if (input < 0)
	{
		len++;
		input *= -1;
	}

	while (copy / 10 != 0)
	{
		copy /= 10;
		len++;
	}
	numStr = malloc(sizeof(*numStr) * (len + 1 + 1));

	if (numStr == NULL)
		return (NULL);

	end = 0;
	if (copy < 0)
	{
		numStr[0] = '-';
		end = 1;
	}

	for (i = len - 1; i >= end; i--)
	{
		numStr[i] = input % 10 + '0';
		input /= 10;
	}

	return (numStr);
}

/**
 * print_array - prints an array of strings.
 * @array: array to print
 */
void print_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		_puts(array[i]);
		_putchar('\n');
		i++;
	}
	if (array[i] == NULL)
		_puts("NULL\n");

}

