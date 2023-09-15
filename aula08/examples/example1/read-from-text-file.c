#include <stdio.h>

int main(){

    FILE *file = fopen("arquivo.txt", "r");

    int newVar;

    fscanf(file, "%d", &newVar);

    printf("O valor lido foi: %d\n", newVar);

    fclose(file);

    return 0;
}