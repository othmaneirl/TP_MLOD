#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

struct prixTuring
{
    char nom_prenom[50] ;
    int annee;
    char domaine[500];
};

int NumberOfWinners(FILE* f);
void ReadWinners(FILE* f);



