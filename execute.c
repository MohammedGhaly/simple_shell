#include "main.h"

void execute(char **command)
{
	char *path_to_execute;

	if (access(command[0], F_OK) == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
                        write_string(file_name);
                        exit(98);
                }
	}
	else if ((path_to_execute = get_path(command[0])) != NULL)
	{
		command[0] = path_to_execute;
		if (execve(command[0], command, NULL) == -1)
		{
			write_string(file_name);
			exit(98);
		}
	}
	else
	{
		write_string(file_name);
		write_string(": No such file or directory\n");
		exit(98);
	}
}
