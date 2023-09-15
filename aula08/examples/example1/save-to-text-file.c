#include <stdio.h>

int main(){
    FILE *file;
    
    file = fopen("arquivo.txt", "w");
    
    int var = 800;

    fprintf(file, "%d", var);

    fclose(file);

    return 0;
}