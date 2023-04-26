#include "main.h"

/**
 * prepare_command - devides the words of the command to be ready for execve()
 * @text: the full line command
 * Return: Success
 */
void prepare_command(char *text)
{
	char **command;
	char *word;
	char *piece = NULL;
	char *delim = " \t\n";
	int i, execute_res, command_words = 0;

	command = malloc(sizeof(char *) * (count_words(text) + 1));
	word = strtok(text, delim);
	i = 0;
	while (word != NULL)
	{
		piece = malloc(_strlen(word) + 1);
		_strcpy(piece, word);
		command[i] = piece;
		command_words++;
		word = strtok(NULL, delim);
		i++;
	}
	command[i] = NULL;
	execute_res = execute(command);
	free_strings(command, command_words);
	free(command);
	if (execute_res == -1)
		exit(98);
}
