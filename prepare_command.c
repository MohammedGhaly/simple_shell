#include "main.h"

void prepare_command(char *text)
{
    char **command = malloc(1024 * sizeof(char *));
    char *word;
    char *delim = " \t\n";
    int i;

    word = strtok(text, delim);
    i = 0;
    while (word != NULL)
    {
        command[i] = word;
        word = strtok(NULL, delim);
        i++;
    }
    command[i] = NULL;
    execute(command);
}
