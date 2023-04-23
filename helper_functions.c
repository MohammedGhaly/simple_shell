#include "main.h"

void print_strings(char **strings)
{
	int i = 0;

	for (; strings[i]; i++)
		printf("%s\n", strings[i]);
}

void free_strings(char **strings)
{
	int i = 0;
	while (!strings[i])
	free(strings[i]);
}

char *removeFirstNCharacters(char* str, int n)
{
	int i;
	char *result;
	int len;

	if (str == NULL)
		return NULL;

	len = _strlen(str);

	if (n <= 0 || n >= len)
		return str;

	result = (char*)malloc((len - n + 1) * sizeof(char));
	if (result == NULL)
		return NULL;

	for (i = n; i < len; i++) {
		result[i - n] = str[i];
	}
	result[len - n] = '\0';

	return result;
}

void ctrlC(int sig)
{
	(void) sig;
	write(1, "\n<3 ", 4);
}
