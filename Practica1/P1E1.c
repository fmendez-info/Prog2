#include <stdio.h>

int main(){
    int N;

    printf("Ingrese tamaño de la matriz\n");
    scanf("%d", &N);

    int M[N][N];


    // Carga matriz identidad
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j){
                M[i][j]=1;
            } else {
                M[i][j]=0;
            }
        }
    }

    // Carga matriz identidad inversa
    /* for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==N-1-j){
                M[i][j]=1;
            } else {
                M[i][j]=0;
            }
        }
    } */

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d  ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}