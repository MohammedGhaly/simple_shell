#include "main.h"

/**
 * write_exist_error - prints error if command doesn't exist
 * Return: Success
 */
void write_exist_error(void)
{
	write_string(file_name);
	write_string(": No such file or directory\n");
}
