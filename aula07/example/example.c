#include <stdio.h>

void imprimeNumero(int n){
    
    printf("%d\n", n);

    if(n == 0)
        return;
    
    imprimeNumero(n-1);

}

int main(){
    imprimeNumero(3);
    return 0;
}