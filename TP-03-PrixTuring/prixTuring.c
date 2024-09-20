#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "prixTuring.h"

int NumberOfWinners(FILE* f) {
    int compteur = 0;
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        compteur++; 
    }
    return compteur;
}

void ReadWinners(FILE* f, prixTuring* tabTuring, int numWinners) {
    char buffer[1000];
    int i = 0;
    rewind(f);

    while (fgets(buffer, sizeof(buffer), f) != NULL && i < numWinners) {
        char* token = strtok(buffer, ";");
		if (token != NULL) {
			tabTuring[i].annee = atoi(token);
		}
        token = strtok(NULL, ";");
        if (token != NULL) {
			tabTuring[i].nom_prenom = malloc(strlen(token) + 1);  // +1 pour \0
            strcpy(tabTuring[i].nom_prenom, token);
        }
        token = strtok(NULL, ";");
        if (token != NULL) {
			tabTuring[i].domaine = malloc(strlen(token) + 1);   //pareil
            strcpy(tabTuring[i].domaine, token);
        }
        i++;
    }
}

void PrintWinners(FILE* f, prixTuring Gagnant){
	fprintf(f,"%s;%s;%s\n",Gagnant.annee,Gagnant.nom_prenom,Gagnant.annee);
}

int main(int argc, char** argv) {
    char filename[] = "turingWinners.csv";
    FILE *f = fopen(filename, "r");
    
    if (f == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }
    
    int numWinners = NumberOfWinners(f);
    if (numWinners == 0) {
        printf("Aucun gagnant trouvé\n");
        fclose(f);
        return 1;
    }else{
		printf("%d gagants\n",numWinners);
	}

    prixTuring *tabTuring = malloc(numWinners * sizeof(prixTuring));
    if (tabTuring == NULL) {
        perror("Erreur d'allocation mémoire");
        fclose(f);
        return 1;
    }

    ReadWinners(f, tabTuring, numWinners);
    fclose(f);

    printf("Le nom du quinzieme laureat est %s\n", tabTuring[14].nom_prenom);
	printf("En %d\n", tabTuring[14].annee);
	printf("Le domaine: %s\n", tabTuring[14].domaine);
	FILE *file = fopen("example.txt", "a");
	prixTuring nouveauGagnant;
	nouveauGagnant.annee=2024;
	nouveauGagnant.nom_prenom = malloc(sizeof(char*)*11);
	nouveauGagnant.domaine = malloc(sizeof(char*)*67);
	strcpy(nouveauGagnant.nom_prenom, 'Avi Widgerson');
	strcpy(nouveauGagnant.domaine, "Pour avoir modifié notre compréhension du rôle du hasard dans l'informatique");
	PrintWinners(file,nouveauGagnant);
	free(nouveauGagnant.nom_prenom);
	free(nouveauGagnant.domaine);









    for (int i=0;i< numWinners;i++){
		free(tabTuring[i].domaine);
		free(tabTuring[i].nom_prenom);
	}
    free(tabTuring);

    return EXIT_SUCCESS;
}