#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>


int main()
{
    int bufLength;
    int fileDescriptor;
    int writeInfo;
    int seekInfo;
    int readInfo;
    int buf;


    //Fajl megnyitas open()-el
    fileDescriptor = open("C:\Users\miron\OneDrive\Desktop\Miron\Egyetem\2.félév\Os\OSGyak\F4XQRO_0405\F4XQRO_openclose\F4XQRO.txt", O_RDWR);
    if(fileDescriptor == -1){
        perror("open() hiba");
        exit(fileDescriptor);
    }

    printf("File Descriptor erteke: %d\n", fileDescriptor);


    //pozícionálás
    seekInfo = lseek(fileDescriptor, 0, SEEK_SET);
    if(seekInfo == -1){
        perror("A pozicionalas nem volt sikeres");
        exit(seekInfo);
    }

    //olvasás
    readInfo = read(fileDescriptor, buf, 15);
    if(readInfo == -1){
        perror("Az olvasas sikertelen\n");
        exit(seekInfo);
    }
    printf("A read() erteke: %d\n", readInfo);
    printf("A beolvasott ertek: %s", buf);


    //írás write()al
    strcpy(buf, "Ez egy teszt");
    bufLength = strlen(buf);
    writeInfo = write(fileDescriptor, buf, bufLength);

    if(writeInfo == -10) {
        perror("Az iras nem volt sikeres");
        exit(writeInfo);
    }

    printf("A write()-al beirt byte-ok szama: %d", writeInfo);
    return 0;
}
