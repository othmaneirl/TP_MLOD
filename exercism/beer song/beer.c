#include "beer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
    for (int i = 0; i < take_down; i++) {
        char *verse1 = malloc(512);
        char *verse2 = malloc(512);
        char *verse3 = malloc(512);
        if (start_bottles == 0) {
            sprintf(verse1, "No more bottles of beer on the wall, no more bottles of beer.");
            sprintf(verse2, "Go to the store and buy some more, 99 bottles of beer on the wall.");
            verse3[0] = '\0';
        } else if (start_bottles == 1) {
            sprintf(verse1, "1 bottle of beer on the wall, 1 bottle of beer.");
            sprintf(verse2, "Take it down and pass it around, no more bottles of beer on the wall.");
            verse3[0] = '\0';
        } else if (start_bottles == 2) {
            sprintf(verse1, "2 bottles of beer on the wall, 2 bottles of beer.");
            sprintf(verse2, "Take one down and pass it around, 1 bottle of beer on the wall.");
            verse3[0] = '\0';
        } else {
            sprintf(verse1, "%d bottles of beer on the wall, %d bottles of beer.", start_bottles, start_bottles);
            sprintf(verse2, "Take one down and pass it around, %d bottles of beer on the wall.", start_bottles - 1);
            verse3[0] = '\0';
        }
        printf("%s\n%s\n%s\n", verse1, verse2, verse3);
        song[i * 3] = verse1;
        song[i * 3 + 1] = verse2;
        song[i * 3 + 2] = verse3;
        start_bottles--;  
    }
}
int main() {
    uint8_t start_bottles = 99;
    uint8_t take_down = 2;
    char **song = malloc(take_down * sizeof(char*));
    recite(start_bottles, take_down, song);
    for (int i = 0; i < take_down; i++) {
        free(song[i]);
    }
    free(song);
    return 0;
}