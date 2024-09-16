#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dates.h"
#include "dates.c"
int main(void){
    Date d;
    initialiseDate(&d);
    afficheDate(&d);
}