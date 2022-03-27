#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

static void char_ki(char *);

int main()
{
    pid_t pid;

    if ( (pid = fork()) < 0)
        perror("fork error");
    else if (pid == 0)
    {
        char_ki("Gyermek processz kimenete\n");
    }
    else
    {
        char_ki("Szulo processz kimenete\n");
    }

    return 0;
}

static void char_ki(char *str)
{
    char *ptr;
    int c;

    setbuf(stdout, NULL);
    for(ptr = str; c = *ptr++;)
            putc(c, stdout);
}
