// 1.5. Copiar texto
// Escribe un programa que copie el contenido de un archivo origen.txt a otro
// archivo copia.txt.

#include <stdio.h>

int main(){
    char texto[100];
    FILE* porigen = fopen("origen.txt","r");
    FILE* pdestino = fopen("copia.txt","w");
    if(porigen==NULL){
        printf("El archivo no existe\n");
    } else {
        while(feof(porigen) == 0){
            fgets(texto,100,porigen);
            fputs(texto,pdestino);
        }
        fclose(porigen);
        fclose(pdestino);
    }
    return 0;
}