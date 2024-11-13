// 1.9. Almacenar y leer estructuras en un archivo binario
// Crea un programa que guarde una lista de estudiantes en un archivo binario
// estudiantes.dat. Cada estudiante tiene un nombre, una edad y un promedio
// de calificaciones. Luego, el programa debe leer y mostrar todos los estudiantes
// guardados.

#include <stdio.h>

typedef struct {
    char nombre[30];
    int edad;
    float promedio;
} Estudiante;

int main(){
    Estudiante estud, registro;

    FILE* archivo = fopen("estudiantes.dat","wb+");

    if (archivo==NULL){
        printf("El archivo no existe");
    } else {
        for (int i=0; i<10; i++){ // aca genero estudiantes y por cada uno lo muestro en pantalla y lo escribo en el archivo
            sprintf(estud.nombre, "Alumno %d", i+1);
            estud.edad = (i+1)*3;
            estud.promedio = (((i+1)*15)%13)*2.0/7.0;
            printf("%s, %d, %f \n", estud.nombre, estud.edad, estud.promedio); //muestro el estudiante
            fwrite(&estud, sizeof(estud), 1, archivo);  //escribo el estudiante completo en el archivo
        }
        rewind(archivo); //vuelvo el cursor al inicio del archivo
        printf("Leyendo\n");
        for (int i=0; i<10; i++){
            fread(&registro, sizeof(registro), 1, archivo); //leo cada estudiante y lo guardo en registro
            printf("%s, %d, %f \n", registro.nombre, registro.edad, registro.promedio); //desde registro muestro los datos del estudiante
        }
        fclose(archivo);
    }
    return 0;
}