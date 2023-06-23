#include <stdio.h>

struct s_data {
    int day;
    int month;
    int year;
};

typedef struct s_data Data;

void printData(Data d){
    printf("%d-%d-%d\n", d.year, d.month, d.day);
}

int main(){

    Data data;

    data.day = 23;
    data.month = 6;
    data.year = 23;

    printData(data);

    return 0;
}