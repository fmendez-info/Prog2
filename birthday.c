#include <stdio.h>
#include <stdlib.h>

int main() {
    int years = 0;
    int eol = rand() % 100;

    while (years < eol) {
        delay(31536000);
        years++;
        printf("Feliz cumpleaños!\n");
    }
    printf(">>>Buen viaje!\n");

    return 0;
}