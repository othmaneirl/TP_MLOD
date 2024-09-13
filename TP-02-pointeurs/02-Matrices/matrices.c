#include "matrices.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SIZE 5
void matrix_mult(int64_t matriceResultat[SIZE][SIZE], int64_t matrice1[SIZE][SIZE], int64_t matrice2[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matriceResultat[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
            {
                matriceResultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }
}

void matrix_print(int64_t matrice[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        printf("[");
        for (int j = 0; j < SIZE; j++){
            printf(" %lld ", matrice[i][j]); 
        }printf("]\n");  
    }
}
