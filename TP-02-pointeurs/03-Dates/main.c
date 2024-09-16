#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dates.h"
#include "dates.c"


int main(void){
    Date d;
    printf("initialiseDate:");
    initialiseDate(&d);
    Date b;
    printf("\ncreercopie:");
    b=creerDateParCopie();
    Date* pdate;
    printf("\nnewdate:");
    pdate= newDate();

    printf("\ndate avec initialise date:");
    afficheDate(&d);
    printf("\ndate avec creercopie:");
    afficheDate(&b);
    printf("\ndate avec newdate:");
    afficheDate(pdate);
    free(pdate);
}