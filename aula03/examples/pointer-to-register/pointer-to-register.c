#include <stdio.h>

struct s_date {
    int day;
    int month;
    int year;
};

typedef struct s_date Date;

void printDate(Date d){
    printf("%d/%d/%d", d.day, d.month, d.year);
}

int main(){

    Date date;

    // 15/4/1968
    date.day = 15;
    date.month = 4;
    date.year = 1968;

    Date *pointerToDate;

    pointerToDate = &date;

    pointerToDate->day = 20;

    printf("Inside pointerToDate: %p\n", pointerToDate);
    printf("Date: %d/%d/%d\n", pointerToDate->day, pointerToDate->month, pointerToDate->year);

    printf("Printing using printDate function: \n");
    printDate(date);

    return 0;
}