#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
c#include <sys/wait.h>
#define _POSIX_SOURCE


void sig_handler(int signum)
{
    printf("\nInside the handler\n");
}



int main()
{
    signal(SIGINT, sig_handler);

    while (1)
    {
        printf("Inside the main function");
        sleep(1);
    }

    sigset_t sigset;
  int    p[2], status;
  char   c='z';
  pid_t  pid;

  if (pipe(p) != 0)
    perror("pipe() error");
  else {
    if ((pid = fork()) == 0) {
      sigemptyset(&sigset);
      puts("child is letting parent know he's ready for signal");
      write(p[1], &c, 1);
      puts("child is waiting for signal");
      sigsuspend(&sigset);
      exit(0);
    }

    puts("parent is waiting for child to say he's ready for signal");
    read(p[0], &c, 1);
    puts("child has told parent he's ready for signal");

    kill(pid, SIGTERM);

    wait(&status);
    if (WIFSIGNALED(status))
      if (WTERMSIG(status) == SIGTERM)
        puts("child was ended with a SIGTERM");
      else
        printf("child was ended with a %d signal\n", WTERMSIG(status));
    else puts("child was not ended with a signal");

    close(p[0]);
    close(p[1]);
  }
}
    return 0;


