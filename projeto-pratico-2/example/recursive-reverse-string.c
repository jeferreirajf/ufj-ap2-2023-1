#include <stdio.h>
#include <stdlib.h>

void reverseString(int start, int end, char *str1, char *str2) {

    

}

int main() {

    char *str1 = "asdf";

    int str1Size = 4;

    char *str2 = (char*) malloc(sizeof(char) * (str1Size + 1));

    // Reverte a str1 e guarda em str2
    reverseString(0, str1Size, str1, str2);

    // Deve imprimir 'fdsa'
    printf("Str2: %s\n", str2);

    return 0;
}