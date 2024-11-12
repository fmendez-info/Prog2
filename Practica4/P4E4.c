// 1.4. Añadir texto
// Escribe un programa que abra el archivo notas.txt y le a ̃nada (sin sobrees-
// cribir) una nueva l ́ınea con el texto ”Nueva nota: 100”.

#include <stdio.h>

int main(){

    FILE* parchivo = fopen("notas.txt", "a");
    fprintf(parchivo,"\nNueva nota: 100");
    fclose(parchivo);

    return 0;
}