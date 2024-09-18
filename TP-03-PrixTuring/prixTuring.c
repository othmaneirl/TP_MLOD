/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "prixTuring.h"


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>

int NumberOfWinners(FILE* f) {
    int compteur = 0;
    char buffer[50000]; //stocker chaque ligne
    // Lecture du fichier
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        compteur++; 
    }
	return compteur;
}


void ReadWinners(FILE* f){
	char buffer[50000];
	for(int i=0;i<57;i++){
		while (fgets(buffer, sizeof(buffer), f) != NULL) {
		printf("%s", buffer);
    }
	}
}
int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		perror("Error opening file");
		return 1;
	}
	int numWinners = NumberOfWinners(f);
	struct prixTuring tabTuring[numWinners];
    
	// printf("il y a %d gagnants",NumberOfWinners(f));
	ReadWinners(f);
	return EXIT_SUCCESS;
}
