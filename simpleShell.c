#include "main.h"

/**
 * main - Entry point
 * @ac: number of arguments passed to the program
 * @av: list of arguments
 * Return: 0 on Success
 */
int main(int ac, char **av)
{
	(void) ac;
	file_name = av[0];
	signal(SIGINT, ctrlC);
	prompt();
	return (0);
}
