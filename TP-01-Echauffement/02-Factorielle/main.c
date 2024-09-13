#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef short TypeEntier;

unsigned long long factorielle(TypeEntier n) {
    unsigned long long f = 1;
    if (n == 0)
        return 1;
    for (TypeEntier i = 1; i <= n; i++)
        f *= i;
    return f;
}


int main (void){
    for (int i=0; i<16; i++)
        printf("Factorielle de %d : %d\n", i, factorielle(i));
}