#include <stdio.h>

int main(){

    int x = -1;
    int *xPointer = &x;

    printf("xPointer address: %p\n", &xPointer);
    printf("Inside xPointer: %p\n", xPointer);
    printf("Address of x: %p\n", &x);
    printf("Value of where xPointer point: %d\n", (*xPointer) );

    return 0;
}