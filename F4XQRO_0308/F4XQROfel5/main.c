#include	<sys/types.h>
//#include	<sys/wait.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

int
main(void)
{
	pid_t	pid;
				  /* Az eredeti sz�l� indul */
	if ( (pid = fork()) < 0) perror("1.fork hiba");
	else if (pid == 0) {	  /* Az 1. gyermek */

		if ( (pid = fork()) < 0) perror("2.fork hiba");
		else if (pid > 0) /* A 2.gyermek sz�l�je = az 1. gyermek */
			exit(0);  /* az 1. gyermek befejez�dik. */

		sleep(2);         /*Itt a 2. gyermek fut. Kicsit v�r
				    hogy a val�di sz�l�je biztosan kil�pjen */
		printf("A 2. gyermek, sz�l�m pid-je = %d\n", getppid());
		exit(0);
	}			  /* Itt az eredeti sz�l� fut. */

	if (waitpid(pid, NULL, 0) != pid) perror("waitpid hiba");
	/* Az eredeti sz�l� az 1. gyermek termin�l�d�s�ra v�r */

	exit(0);
}
