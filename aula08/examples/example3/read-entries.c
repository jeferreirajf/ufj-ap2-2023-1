#include <stdio.h>

int main(){

    FILE *file = fopen("arquivo.txt", "r");

    int aNumber;

    while(fscanf(file, "%d", &aNumber) == 1){
        printf("Read number: %d\n", aNumber);
    }

    fclose(file);

    return 0;
}