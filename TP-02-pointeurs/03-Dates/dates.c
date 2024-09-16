#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dates.h"

void initialiseDate(struct Date *date) {
    printf("Entrer le jour : ");
    scanf("%d", &date->jour);
    
    int mois_entre;
    printf("Entrer le mois (1-12) : ");
    scanf("%d", &mois_entre);
    date->mois = (enum Mois)mois_entre;

    printf("Entrer l'annee : ");
    scanf("%d", &date->annee);
    

}

void afficheDate(struct Date *date) {
    printf("Date : %d/%d/%d\n", date->jour, date->mois, date->annee);
}

