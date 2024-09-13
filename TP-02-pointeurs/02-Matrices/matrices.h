#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SIZE 5
void matrix_mult(int64_t matriceResultat[SIZE][SIZE], int64_t matrice1[SIZE][SIZE], int64_t matrice2[SIZE][SIZE]);
void matrix_print(int64_t matrice[SIZE][SIZE]);