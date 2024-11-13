// 1.8. Buscar y reemplazar palabras
// Crea un programa que abra un archivo documento.txt y reemplace todas
// las ocurrencias de una palabra espec ́ıfica (por ejemplo, ”vieja”) por otra palabra
// (por ejemplo, ”nueva”). El resultado debe guardarse en un archivo nuevo llamado
// documento modificado.txt.

// NO ESTA TERMINADO

#include <stdio.h>
#include <string.h>

int main(){
    int anterior=0, letra=0;
    char palabra[15], caracter;
    char palabraareemp[] = "hola";
    char palabranueva[] = "chau";

    FILE* parchivo = fopen("documento.txt","r");
    if(parchivo == NULL){
        printf("El archivo no existe\n");
    } else {
        while(feof(parchivo) == 0){
            caracter=fgetc(parchivo);
            if(isalnum(caracter)){
                anterior=1;
                palabra[letra]=caracter;
                letra++;
            } else {
                if(anterior==1){
                    //termino la palabra
                    if(strcmp(palabra,palabraareemp)){
                        //reemplazar la palabra
                    }
                    letra=0;
                }
                anterior=0;
            }
        }
    }

    fclose(parchivo);

    return 0;
}