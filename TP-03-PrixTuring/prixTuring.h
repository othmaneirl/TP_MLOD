#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef struct 
{
    char* nom_prenom ; // se termine par \0
    int annee;
    char* domaine; // se termine par \0
} prixTuring;

int NumberOfWinners(FILE* f);
void ReadWinners(FILE* f, prixTuring* tabTuring, int numWinners);
void PrintWinners(FILE* f, prixTuring Gagnant);
void infoAnnee(int Year, prixTuring* tabTuring,int nbWinners);