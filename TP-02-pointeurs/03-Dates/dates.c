#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dates.h"

void initialiseDate(Date *date) {
    printf("Entrer le jour : ");
    scanf("%d", &date->jour);

    int mois_entre;
    printf("Entrer le mois (1-12) : ");
    scanf("%d", &mois_entre);
    date->mois = (enum Mois)mois_entre;

    printf("Entrer l'annee : ");
    scanf("%d", &date->annee);
    

}
Date creerDateParCopie(void){
    struct Date d;
    printf("Entrer l'annee : ");
    scanf("%d",&d.annee);
    int mois_entre;
    printf("Entrer le mois : ");
    scanf("%d", &mois_entre);
    d.mois= (enum Mois) mois_entre;
    printf("Entrer le jour : ");
    scanf("%d", &d.jour);
    return d;
}
void afficheDate(Date *date) {
    printf("%d/%d/%d\n", date->jour, date->mois, date->annee);
}

