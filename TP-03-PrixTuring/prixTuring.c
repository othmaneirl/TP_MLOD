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

void PrintWinners(FILE* output, prixTuring Gagnant){
	fprintf(output,"%d;%s;%s",Gagnant.annee,Gagnant.nom_prenom,Gagnant.domaine);
}

void infoAnnee(int Year, prixTuring* tabTuring,int nbWinners){
    prixTuring listeAnne[nbWinners];
    int index = 0;
    for (int i=0; i<nbWinners;i++){
        if (tabTuring[i].annee==Year){
            listeAnne[index]=tabTuring[i];
            index++;
        }
    }
    printf("durant l'annee %d, le ou les gagnant sont:\n",Year);
    for (int j=0; j<index;j++){
        printf("%s dans le domaine %s",listeAnne[j].nom_prenom,listeAnne[j].domaine);
    }
}

void sortTuringWinnersByYear(FILE* f, prixTuring* tabTuring, int nbWinners){
    for (int i = 0; i < nbWinners - 1; i++) {
        for (int j = 0; j < nbWinners - 1 - i; j++) {
            if (tabTuring[j].annee > tabTuring[j + 1].annee) {
                prixTuring temp = tabTuring[j];
                tabTuring[j] = tabTuring[j + 1];
                tabTuring[j + 1] = temp;
            }
        }
    } //le tableau est maintenant trié donc on peut l'écrire dans l'output
	for (int i=0;i<nbWinners;i++){
		PrintWinners(f,tabTuring[i]);
	}
	fclose(f);
}

int main(int argc, char *argv[]) {
//=================================================
    // FILE *f = fopen(argv[1], "r");                        décommenter pour pouvoir entrer le nom du fichier input lors de l'exection du .out
//=================================================

    FILE *f = fopen("turingWinners.csv","r");
    
    if (f == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    }
    
    int numWinners = NumberOfWinners(f);

// Pour le nombre de gagnants 
//=================================================
    // if (numWinners == 0) {
    //     printf("Aucun gagnant trouvé\n");
    //     fclose(f);
    //     return 1;
    // }else{
	// 	printf("%d gagants\n",numWinners);
	// }
//=================================================
    prixTuring *tabTuring = malloc(numWinners * sizeof(prixTuring));
    if (tabTuring == NULL) {
        perror("Erreur d'allocation mémoire");
        fclose(f);
        return 1;
    }
    ReadWinners(f, tabTuring, numWinners);
    fclose(f);
    FILE *sorted = fopen("sortedTuringWinners.csv","w");
    sortTuringWinnersByYear(sorted,tabTuring,numWinners);

// Pour afficher les infos des gagants
//=================================================
    // printf("Le nom du quinzieme laureat est %s\n", tabTuring[14].nom_prenom);
	// printf("En %d\n", tabTuring[14].annee);
	// printf("Le domaine: %s\n", tabTuring[14].domaine);
//=================================================

// Pour afficher les gagnants de l'année entrée dans le .out
//=================================================
    // int year = atoi(argv[1]);  //conversion du char* argv[1] en int
    // infoAnnee(year,tabTuring,numWinners);  //affiche les infos sur les gagnants de l'année entrée lors de l'execution du .out 
//=================================================



    // pour créer l'output
//=================================================
	// FILE *file = fopen(argv[2], "w");
	// for (int i=0;i<numWinners;i++){
	// 	PrintWinners(file,tabTuring[i]);
	// }
	// fclose(file);
//=================================================

    for (int i=0;i< numWinners;i++){
		free(tabTuring[i].domaine);
		free(tabTuring[i].nom_prenom);
	}
    free(tabTuring);

    return EXIT_SUCCESS;
}