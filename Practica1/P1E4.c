#include <stdio.h>

int main(){
    int F, C;

    printf("Ingrese filas de la matriz\n");
    scanf("%d", &F);

    printf("Ingrese columnas de la matriz\n");
    scanf("%d", &C);

    int M[F][C];

    for(int fila=0; fila<F; fila++){
        for(int col=0; col<C; col++){
            printf("Ingrese M1 (%d,%d): ", fila+1, col+1);
            scanf("%d", &M[fila][col]);
        }
    }

    printf("Matriz 1:\n");
    for(int fila=0; fila<F; fila++){
        for(int col=0; col<C; col++){
            printf("%d  ", M[fila][col]);
        }
        printf("\n");
    }
}