#include <stdio.h>

struct s_data {
    int day;
    int month;
    int year;
} data1;

int main(){
    FILE *file = fopen("binary-file.bin", "rb");

    if(file == NULL){
        return 0;
    }

    fread(&data1, sizeof(data1), 1, file);

    fclose(file);

    printf("%d/%d/%d\n", data1.day, data1.month, data1.year);

    return 0;
}