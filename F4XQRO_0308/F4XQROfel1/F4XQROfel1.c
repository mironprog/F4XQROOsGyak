#include <stdio.h>
#include <stdlib.h>

int main()
{
    if (!system("dir")){
        for(int i = 0; i < 3; i++){
            printf("KORTE\n");
        }
    }

    system("color a");
    system("Nincs ilyen parancs");
    return 0;
}
