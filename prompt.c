#include "main.h"

/**
 * prompt - repeats the process of asking the user for a command
 * Return: Success
 */
void prompt(void)
{
	while (1)
	{
		write_string("$ ");
		recieve_command();
	}
}
