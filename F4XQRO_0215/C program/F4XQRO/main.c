#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("vezeteknev.txt", "w+");

    fprintf(fp, "%s", "Bojan Miron Noel");
    fprintf(fp, "%s", "\nF4XQRO");
    fprintf(fp, "%s", "\nProgramtervezo informatikus");


    fclose(fp);
    return 0;
}
