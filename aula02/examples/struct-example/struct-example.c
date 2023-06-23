#include <stdio.h>

struct {
    int day;
    int month;
    int year;
} data, data2;

int main(){

    data.day = 23;
    data.month = 6;
    data.year = 23;

    data2.day = 5;
    data2.month = 6;
    data2.year = 24;

    printf("%d/%d/%d\n", data.day, data.month, data.year);

    return 0;
}