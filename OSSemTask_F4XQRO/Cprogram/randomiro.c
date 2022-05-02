#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main (int argc, char* argv[])
{

	//legenráljuk a random számot
	srand(time(NULL));
	int randomNumber = rand() % 100;
	
	
	//megnyitjuk írásra a csővezetéket
	int fd = open("myfifo1", O_WRONLY);
	if(fd == -1) {
		return -1;
	}
	
	//beleírjuk a számiunkat
	write(fd, &randomNumber, sizeof(int));
	
	printf("A generalt szam: %d\n", randomNumber);
	
	
	//kiolvassa a kapott számot és kíírja
	int dupla;
	read(fd, &dupla, sizeof(int));
	printf("A visszakapott szam duplaja: %d\n", dupla);
	
	unlink("myfifo1");
	
	close(fd);
	
	

	return 0;
}
