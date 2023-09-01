#include <stdio.h>

int somatoria(int n){

    if(n == 1)
        return 1;

    return n * n + somatoria(n-1);

}

int main(){
    int n = 4;

    int resultado = somatoria(n);

    printf("O resultado com n=%d e: %d\n", n, resultado);
}