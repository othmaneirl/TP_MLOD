#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dates.h"
#include "dates.c"
int main(void){
    Date d;
    initialiseDate(&d);
    Date b;
    b=creerDateParCopie();
    printf("date avec initialise date");
    afficheDate(&d);
    printf("\ndate avec creercopie");
    afficheDate(&b);
}