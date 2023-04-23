#include "main.h"

void recieve_command(void)
{
    char *text = NULL;
    size_t buffer_size = 0;
    int lenbuf, child_pid, status;

    lenbuf = getline(&text, &buffer_size, stdin);
    if (lenbuf == -1)
        exit(98);
    if (compare_chars(text, "exit\n", 6))
        exit(0);
    if (compare_chars(text, "env\n", 5))
    {
        print_strings(environ);
        free(text);
        return;
    }
    else
    {
        child_pid = fork();
        if (child_pid < 0)
            perror("Error");
        else if (child_pid == 0)
            prepare_command(text);
        else
            wait(&status);
    }
}
