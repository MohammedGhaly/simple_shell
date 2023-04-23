#include "main.h"

void prompt(void)
{
    while (1)
    {
        write_string("$ ");
        recieve_command();
    }
}
