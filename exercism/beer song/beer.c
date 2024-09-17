#include "beer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
    for (int i = 0; i < take_down; i++) {
        char *verse = malloc(1024);
        if (start_bottles == 0) {
            sprintf(verse, "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n");
        } else if (start_bottles == 1) {
            sprintf(verse, "1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n");
        } else if (start_bottles == 2) {
            sprintf(verse, "2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n");
        } else {
            sprintf(verse, "%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottles of beer on the wall.\n",
                                  start_bottles, start_bottles, start_bottles - 1);
        }
        printf("%s\n", verse);
        song[i] = verse;
        start_bottles--;  
    }
}
