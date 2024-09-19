#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef struct 
{
    char nom_prenom[50] ;
    char annee[4];
    char domaine[500];
} prixTuring;

int NumberOfWinners(FILE* f);
void ReadWinners(FILE* f, prixTuring* tabTuring, int numWinners);



