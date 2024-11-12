// 1.1. Hola Mundo
// Escribe un programa en C que cree un archivo de texto llamado saludo.txt
// y escriba el texto ”Hola, mundo!.en  ́el. Si el archivo ya existe, que la l ́ınea se
// agregue.

#include <stdio.h>

int main(){

    FILE* parchivo = fopen("saludo.txt", "a");
    fprintf(parchivo,"Hola, mundo!.\n");
    fclose(parchivo);

    return 0;
}