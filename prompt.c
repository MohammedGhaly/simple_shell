#include "main.h"

/**
 * prompt - repeats the process of asking the user for a command
 * Return: Success
 */
void prompt(void)
{
	if (!isatty(0))
	{
		recieve_command();
		return;
	}
	while (1)
	{
		write_string("$ ");
		recieve_command();
	}
}
