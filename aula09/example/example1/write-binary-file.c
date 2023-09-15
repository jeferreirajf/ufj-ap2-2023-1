#include <stdio.h>

struct s_data {
    int day;
    int month;
    int year;
} data1;

int main(){

    data1.day = 15;
    data1.month = 9;
    data1.year = 2023;

    FILE *file;

    file = fopen("binary-file.bin", "wb");

    fwrite(&data1, sizeof(data1), 1, file);

    fclose(file);   

    return 0;
}