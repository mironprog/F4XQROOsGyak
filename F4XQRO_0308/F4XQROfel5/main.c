#include	<sys/types.h>
//#include	<sys/wait.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

int
main(void)
{
	pid_t	pid;
				  /* Az eredeti szülõ indul */
	if ( (pid = fork()) < 0) perror("1.fork hiba");
	else if (pid == 0) {	  /* Az 1. gyermek */

		if ( (pid = fork()) < 0) perror("2.fork hiba");
		else if (pid > 0) /* A 2.gyermek szülõje = az 1. gyermek */
			exit(0);  /* az 1. gyermek befejezõdik. */

		sleep(2);         /*Itt a 2. gyermek fut. Kicsit vár
				    hogy a valódi szülõje biztosan kilépjen */
		printf("A 2. gyermek, szülõm pid-je = %d\n", getppid());
		exit(0);
	}			  /* Itt az eredeti szülõ fut. */

	if (waitpid(pid, NULL, 0) != pid) perror("waitpid hiba");
	/* Az eredeti szülõ az 1. gyermek terminálódására vár */

	exit(0);
}
