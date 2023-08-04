#include <stdio.h>

int readInteger(char* message){
    int integer;

    printf("%s", message);
    scanf("%d", &integer);

    return integer;
}

int calculateFactorial(int n){
    int factorial = 1;

    int i = 0;

    for(i = 1; i <= n; i++){
        factorial *= i;
    }

    printf("%d", i);

    return factorial;
}

float sum(int n){
    float result = 1.0f;

    for(int i = 1; i <= n; i++){
        result = result + 1.0f / calculateFactorial(i);
    }

    return result;
}

int main(){
    
    int n = readInteger("Digite um inteiro: ");

    float result = sum(n);

    printf("1 + 1/1! 1/2! + ... + 1/%d! = %f\n", n, result);
    
    return 0;
}