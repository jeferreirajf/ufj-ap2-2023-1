#include <stdio.h>
#include <stdlib.h>

#define n 3
#define m 2

// Objetivo é criar dinamicamente uma matrix[n][m]
int main()
{

    int **matrix = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = i * j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Matrix[%d][%d]: %d\n", i, j, matrix[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}