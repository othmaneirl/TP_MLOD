#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
    char annee[10];
    char nom_prenom[100];
    char domaine[100];
} prixTuring;

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
        buffer[strcspn(buffer, "\n")] = 0;

        char* token = strtok(buffer, ";");
        if (token != NULL) {
            strcpy(tabTuring[i].annee, token);
        }
        token = strtok(NULL, ";");
        if (token != NULL) {
            strcpy(tabTuring[i].nom_prenom, token);
        }
        token = strtok(NULL, ";");
        if (token != NULL) {
            strcpy(tabTuring[i].domaine, token);
        }
        i++;
    }
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
	printf("En %s\n", tabTuring[14].annee);
	printf("Le domaine: %s\n", tabTuring[14].domaine);
    
    free(tabTuring);

    return EXIT_SUCCESS;
}