#include <stdio.h>

int main(){

    int n;

    printf("Informe o valor de n: ");
    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++){
        int tmp;

        printf("Informe o elemento %d: ", i+1);
        scanf("%d", &tmp);

        v[i] = tmp;
    }

    for(int i = 0; i < n; i++)
        printf("%d\n", v[i] * 2);

    return 0;
}