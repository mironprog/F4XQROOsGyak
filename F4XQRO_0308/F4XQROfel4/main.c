#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    pid_t pid;

    if( (pid = fork()) < 0)
        perror("fork error");
    else if(pid == 0)

    return 0;
}
