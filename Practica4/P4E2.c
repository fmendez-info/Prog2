// 1.2. Leer desde un archivo
// Escribe un programa que lea el contenido de un archivo llamado datos.txt
// y lo muestre en pantalla. Si el archivo no existe, debe mostrar un mensaje de
// error.

#include <stdio.h>

int main(){
    char texto[100];
    FILE* parchivo = fopen("datos.txt","r");
    if(parchivo==NULL){
        printf("El archivo no existe\n");
    } else {
        while(feof(parchivo) == 0){
            fgets(texto,100,parchivo);
            printf("%s", texto);
        }
        fclose(parchivo);
    }
    printf("\n");
    return 0;
}