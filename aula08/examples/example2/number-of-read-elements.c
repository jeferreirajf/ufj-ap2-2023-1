#include <stdio.h>

int main()
{
    FILE *file = fopen("arquivo.txt", "w+");

    int randomNumber = 900;

    fprintf(file, "%d\n", randomNumber);

    fclose(file);

    file = fopen("arquivo.txt", "r");

    int readNumber;
    int nNumbers;

    nNumbers = fscanf(file, "%d", &readNumber);

    printf("nNumbers: %d\n", nNumbers);
    printf("readNumber: %d\n", readNumber);

    fclose(file);

    return 0;
}