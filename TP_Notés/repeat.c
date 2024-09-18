//Fait par Othmane IRHBOULA 
#include <stdio.h>
#include <stdlib.h>

int* repeat(int t1[], int t2[], int size) {
    int taille_totale = 0;
    for (int i = 0; i < size; i++) {    //on calcule la taille totale du tableau résultat
        taille_totale += t1[i];
    }
    
    int* res = (int*)malloc(taille_totale * sizeof(int));
    int* recup_taille = res-1;       
    *recup_taille = taille_totale;   //on stocke la taille du tableau résultat à l'adresse précédente de res
    
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < t1[i]; j++) {
            res[index] = t2[i];
            index++;
        }
    } //on remplit le tableau résultat avec les valeurs de t2 en fonction des valeurs de t1

    return res;  //on retourne l'adresse du tableau résultat
}


void print_tableau(int t[], int taille) {   //fonction pour afficher un tableau
    printf("[");
    for (int i = 0; i < taille; i++) {
        printf("%d", t[i]);
        if (i < taille - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

int main(void) {
    int t1[3] = {1, 2, 4};
    int t2[3] = {10, 3, 8};

    int t3[4] = {1, 2, 3, 4};
    int t4[4] = {10, 3, 8, 2};

    int* ptr = repeat(t1, t2, 3);
    int* ptr2 = repeat(t3, t4, 4);

    printf("Tableau 1 : ");
    print_tableau(ptr, *(ptr-1));  //l'adresse ptr-1 contient la taille du tableau résultat précedemment calculée
    printf("\nTableau 2 : ");
    print_tableau(ptr2, *(ptr2-1)); //l'adresse ptr2-1 contient la taille du tableau résultat précedemment calculée

    free(ptr);
    free(ptr2);
    return 0;
}