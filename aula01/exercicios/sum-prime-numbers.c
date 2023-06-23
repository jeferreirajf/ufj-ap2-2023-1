#include <stdio.h>

void printPrimeSum(int *v, int n){

    int sum = 0;

    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0)
            sum += v[i];
    }

    printf("A soma dos numeros pares e: %d\n", sum);

}

int main(){

    int v[] = {1, 2, 3, 4, 5, 6, 7, 0, 2, 1, 0, 2};
    // int v[12];
    // v[0] = 1;
    // v[1] = 2;
    // v[3] = 3;
    // ...
    // v[11] = 2;

    printPrimeSum(v, 12);

    return 0;
}