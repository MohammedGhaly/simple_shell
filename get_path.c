#include "main.h"

/**
 * get_path - checks every possible path and chooses the right one
 * @command: a command like (ls) or (pwd)
 * Return: string of the full path of the command
 */
char *get_path(char *command)
{
	int i = 0;
	struct stat st;
	char **p_commands;

	p_commands = get_path_commands(command);
	for (; p_commands[i] != NULL; i++)
	{
		if (stat(p_commands[i], &st) == 0)
			return (p_commands[i]);
	}
	return (NULL);
}

/**
 * get_path_commands - forms the possible file paths of the command
 * @command: ls-like command
 * Return: array of the possible paths of the command file
 */
char **get_path_commands(char *command)
{
	int i = 0;
	char *path_value;
	char **paths = malloc(1024 * sizeof(char *));
	char *word;
	char *delim = ":";

	while (!compare_chars(environ[i], "PATH", 4))
		i++;
	path_value = removeFirstNCharacters(environ[i], 5);
	word = strtok(path_value, delim);
	i = 0;
	while (word != NULL)
	{
		word = concatenate(word, "/");
		paths[i] = concatenate(word, command);
		word = strtok(NULL, delim);
		i++;
	}
	paths[i] = NULL;

	free(path_value);
	return (paths);
}
