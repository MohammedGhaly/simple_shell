#include "main.h"

/**
 * command_exists - checks if the command exists or not
 * @text: string pointer of the command entered
 * Return: 1 if exists, 0 otherwise
 */
int command_exists(char *text)
{
	char *path_to_execute;
	char **command;
	char *word;
	char *piece = NULL;
	char *delim = " \t\n";
	int i, command_words = 0;

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
	if (access(command[0], F_OK) == 0)
		return (1);
	path_to_execute = get_path(command[0]);
	free_strings(command, command_words);
	free(command);
	if (path_to_execute != NULL)
		return (1);
	return (0);
}
