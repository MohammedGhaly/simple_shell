#include "main.h"

/**
 * prepare_command - devides the words of the command to be ready for execve()
 * @text: the full line command
 * Return: Success
 */
void prepare_command(char *text)
{
	char **command = malloc(1024 * sizeof(char *));
	char *word;
	char *delim = " \t\n";
	int i, execute_res;

	word = strtok(text, delim);
	i = 0;
	while (word != NULL)
	{
		command[i] = word;
		word = strtok(NULL, delim);
		i++;
	}
	execute_res = execute(command);
	free_strings(command);
	free(command);
	if (execute_res == -1)
		exit(98);
}
