#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <dirent.h>
#include <limits.h>

int command_exists(char *text);
void free_strings(char **strings, int n);
int write_string(char *str);
void recieve_command(void);
void prepare_command(char *text);
int execute(char **command);
char *get_path(char *command);
int path_execute(char **command);
int path_exists(char *command);
void print_strings(char **strings);
char *concatenate(char *s1, char *s2);
char **get_path_commands(char *command);
int _strlen(char *str);
char *removeFirstNCharacters(char *str, int n);
int compare_chars(char *s1, char *s2, int chars_compared);
void ctrlC(int sig);
void prompt(void);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
int count_words(char *text);
void write_exist_error(void);

char *file_name;
extern char **environ;
#endif /* MAIN_H */
