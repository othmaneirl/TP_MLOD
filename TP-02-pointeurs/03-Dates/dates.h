#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum Mois {Janvier=1, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout, Septembre, Octobre, Novembre, Decembre};
struct Date{
    enum Mois mois;
    int jour, annee;
};
typedef struct Date Date;

void initialiseDate(struct Date *date);
void afficheDate(struct Date *date);
