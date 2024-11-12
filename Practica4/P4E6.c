// 1.6. Contar palabras
// Crea un programa que lea el contenido de un archivo texto.txt (puede ser
// el archivo anterior) y cuente la cantidad total de palabras en el archivo. Una
// palabra se define como una secuencia de caracteres alfanumericos separados por
// espacios, saltos de linea o signos de puntuacion.

#include <stdio.h>
#include <ctype.h>

int main(){
    int anterior=0, palabras=0;
    FILE* parchivo = fopen("texto.txt","r");
    if(parchivo == NULL){
        printf("El archivo no existe\n");
    } else {
        while(feof(parchivo) == 0){
            if(isalnum(fgetc(parchivo))){
                anterior=1;
            } else {
                if(anterior==1){
                    palabras++;
                }
                anterior=0;
            }
        }
        fclose(parchivo);
        printf("Hay %d palabras\n", palabras);
    }

    return 0;
}