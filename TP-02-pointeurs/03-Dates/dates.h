#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum Mois {Janvier=1, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout, Septembre, Octobre, Novembre, Decembre};
char tabMois[12][10] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
struct Date{
    enum Mois mois;
    int jour, annee;
};
typedef struct Date Date;

void initialiseDate(Date *date);
void afficheDate(Date *date);
Date creerDateParCopie(void);
Date* newDate();