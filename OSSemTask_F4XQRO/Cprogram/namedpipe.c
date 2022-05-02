#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main (int argc, char* argv[])
{
	//létrehozza a nevesített csővezetéket
	if(mkfifo("myfifo1", 0777) == -1) {
		if(errno != EEXIST) {
		printf("Could not create fifo file\n");
		return 1;
		}
	}
	
	
	//megnyitja
	printf("Megnyitas....\n");
	int fd = open("myfifo1", O_RDONLY);
	printf("Megnyitva!\n");
	
	int randomNumber;
	
	//kiolvassa a kapott számot és kíírja
	read(fd, &randomNumber, sizeof(int));
	printf("A kapott szam:%d\n", randomNumber);
	
	//visszaadja a dupláját
	int dupla = randomNumber * 2;
	printf("A kapott szam duplaja:%d\n", dupla);
	write(fd, &dupla, sizeof(int));
	
	
	
	close(fd);
	printf("Bezarva\n");
	


	return 0;
}
