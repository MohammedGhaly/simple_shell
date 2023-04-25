#include "main.h"

/**
 * print_strings - prints every string on a single line
 * @strings: array of strings
 * Return: Success
 */
void print_strings(char **strings)
{
	int i = 0;

	for (; strings[i]; i++)
	{
		write_string(strings[i]);
		_putchar('\n');
	}
}

/**
 * free_strings - frees a list of strings
 * @strings: the list of strings
 * Return: success
 */
void free_strings(char **strings)
{
	int i = 0;

	while (!strings[i])
	free(strings[i]);
}

/**
 * removeFirstNCharacters - removes the first n chars of a string
 * @str: string variable
 * @n: number of chars to remove
 * Return: the edited string
 */
char *removeFirstNCharacters(char *str, int n)
{
	int i;
	char *result;
	int len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	if (n <= 0 || n >= len)
		return (str);

	result = (char *)malloc((len - n + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = n; i < len; i++)
		result[i - n] = str[i];
	result[len - n] = '\0';

	return (result);
}

/**
 * ctrlC - handles ctrl + c command
 * @i: garbage variable
 * Return: Success
 */
void ctrlC(int i)
{
	(void) i;
	write(1, "\n$ ", 3);
}
