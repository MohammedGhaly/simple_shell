#include "main.h"

/**
 * execute - processes the command and executes it
 * @command: array of strings forming the command
 * Return: 1 on Success, -1 on Failure
 */
int execute(char **command)
{
	char *path_to_execute;

	if (access(command[0], F_OK) == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			write_string(file_name);
			return (-1);
		}
	}
	else
	{
		path_to_execute = get_path(command[0]);
		if (path_to_execute != NULL)
		{
			command[0] = path_to_execute;
			if (execve(command[0], command, environ) == -1)
			{
				write_string(file_name);
				return (-1);
			}
		}
		else
		{
			write_string(file_name);
			write_string(": No such file or directory\n");
			return (-1);
		}
	}
	return (1);
}
