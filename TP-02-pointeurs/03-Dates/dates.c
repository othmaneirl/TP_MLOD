#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dates.h"
#include "stdbool.h"

void initialiseDate(Date *date) {
    printf("Entrer le jour : ");
    scanf("%d", &date->jour);

    printf("Entrer le mois (1-12) : ");
    scanf("%d",(int*) &date->mois);

    printf("Entrer l'annee : ");
    scanf("%d", &date->annee);
}


Date creerDateParCopie(void){
    struct Date d;
    printf("Entrer l'annee : ");
    scanf("%d",&d.annee);
    printf("Entrer le mois : ");
    scanf("%d", (int*)&d.mois);
    printf("Entrer le jour : ");
    scanf("%d", &d.jour);
    return d;
}



Date* newDate(void){
    Date* date = malloc(sizeof(Date));
    initialiseDate(date);
    return date;
}

void afficheDate(Date *date) {
    printf("Le %d %s %d\n", date->jour, tabMois[date->mois-1], date->annee);
}

