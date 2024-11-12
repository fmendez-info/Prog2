// 1.3. Contar l ́ıneas
// Crea un programa que cuente el n ́umero de l ́ıneas en un archivo de texto
// llamado texto.txt y muestre el resultado en pantalla.

#include <stdio.h>

int main(){
    char texto[100];
    int lineas=0;
    FILE* parchivo = fopen("datos.txt","r");
    if(parchivo==NULL){
        printf("El archivo no existe\n");
    } else {
        while(feof(parchivo) == 0){
            if(fgetc(parchivo) == '\n'){
                lineas++;
            }
        }
        fclose(parchivo);
    }
    printf("lineas: %d\n", lineas+1);
    return 0;
}