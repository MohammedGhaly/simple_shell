#include "main.h"

/**
 * compare_chars - compares to strings
 * @s1: first string
 * @s2: second string
 * @chars_compared: number of chars to compare
 * Return: 1 on Success, 0 otherwise
 */
int compare_chars(char *s1, char *s2, int chars_compared)
{
	int i;

	for (i = 0; ((i < chars_compared) && (s1[i] == s2[i])); i++)
		;
	if (i == chars_compared)
		return (1);
	return (0);
}

/**
 * concatenate - puts s2 at the end of s1 in one string variable
 * @s1: first string
 * @s2: second string
 * Return: the new edited string
 */
char *concatenate(char *s1, char *s2)
{
	int i, j;
	char *res;

	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	res = malloc((_strlen(s1) + _strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);

	i = j = 0;
	for (; s1[i] != '\0'; i++)
	{
		res[i] = s1[i];
	}

	for (; s2[j] != '\0'; j++)
	{
		res[i] = s2[j];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/**
 * _putchar - writes a character to std output
 * @c: character
 * Return: 1 on Success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * write_string - prints a string to the standard output
 * @str: string
 * Return: number of printed chars
 */
int write_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _strlen - calculates the number of chars in a string
 * @str: string variable
 * Return: the length of the string str
 */
int _strlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		;
		return (i);
}
