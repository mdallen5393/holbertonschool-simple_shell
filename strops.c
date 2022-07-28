#include "main.h"

/*
 * FOR TESTING
 * int main(void)
 * {
 *	char *s1 = "ABC";
 *	char *s2 = "ABD";
 *	char *s3 = "ABB";
 *	char *s4 = "ABZ";
 *
 *	printf("%s, %s\n", s1, _strdup(s1));
 * }
 */

/**
 * strcpycat - concats two strings and places them into a newly malloc'd buffer
 * @str1: first string (string being concatenated to)
 * @str2: second string (string to concatenate)
 *
 * Return: pointer to new string, or NULL on failure (malloc)
 */
char *strcpycat(char *str1, char *str2)
{
	char *newStr;
	int l1 = _strlen(str1);
	int l2 = _strlen(str2);
	int i, j;

	newStr = malloc(sizeof(*newStr) * (l1 + l2 + 1));
	if (!newStr)
		return (NULL);

	for (i = 0; i < l1; i++)
		newStr[i] = str1[i];

	for (j = 0; j < l2; j++)
	{
		newStr[i] = str2[j];
		i++;
	}

	newStr[i] = '\0';

	return (newStr);
}

/**
 * _strlen - finds the length of a string (not including '\0')
 * @str: input string
 *
 * Return: integer string length.
 */
int _strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if strings are equal, or difference if not equal.
 */
int _strcmp(const char *s1, const char *s2)
{
	int diff;
	int i;

	diff = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
		}
		i++;
	}

	return (diff);
}

/**
 * _strncmp - compare first n bytes of two strings.
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of bytes to compare
 *
 * Return: integer difference between strings
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int diff;
	size_t i;

	diff = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i] || i == n - 1)
		{
			diff = s1[i] - s2[i];
			break;
		}
		i++;
	}

	return (diff);
}

/**
 * _strdup - duplicates a string (mallocs memory for new string)
 * @str: string to duplicate
 *
 * Return: pointer to new string, NULL on failure to malloc.
 */
char *_strdup(const char *str)
{
	char *duplicate;
	int i, len;

	if (!str)
		return (NULL);

	len = _strlen(str);

	duplicate = malloc(sizeof(*duplicate) * (len + 1));
	if (!duplicate)
		return (NULL);

	for (i = 0; i < len; i++)
		duplicate[i] = str[i];

	duplicate[i] = '\0';

	return (duplicate);
}
