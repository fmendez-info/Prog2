// 1.5. Copiar texto
// Escribe un programa que copie el contenido de un archivo origen.txt a otro
// archivo copia.txt.

#include <stdio.h>

int main(){
    char texto[100];
    FILE* parchivo = fopen("datos.txt","r");
    if(parchivo==NULL){
        printf("El archivo no existe\n");
    } else {
        while(fgets(texto,100,parchivo)){
            fputs("%s", texto);
        }
        fclose(parchivo);
    }
    return 0;
}