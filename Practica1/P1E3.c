#include <stdio.h>

int main(){
    int N;

    printf("Ingrese tamaño de la matriz\n");
    scanf("%d", &N);

    int M1[N][N];
    int M2[N][N];
    int M3[N][N];

    for(int f=0; f<N; f++){
        for(int c=0; c<N; c++){
            printf("Ingrese M1 (%d,%d): ", f+1, c+1);
            scanf("%d", &M1[f][c]);
        }
    }

    printf("Matriz 1:\n");
    for(int f=0; f<N; f++){
        for(int c=0; c<N; c++){
            printf("%d  ", M1[f][c]);
        }
        printf("\n");
    }

    for(int f=0; f<N; f++){
        for(int c=0; c<N; c++){
            printf("Ingrese M2 (%d,%d): ", f+1, c+1);
            scanf("%d", &M2[f][c]);
        }
    }

    printf("Matriz 2:\n");
    for(int f=0; f<N; f++){
        for(int c=0; c<N; c++){
            printf("%d  ", M2[f][c]);
        }
        printf("\n");
    }

    for(int f=0; f<N; f++){
        for(int c=0; c<N; c++){
            M3[f][c]=M1[f][c]+M2[f][c];
        }
    }

    printf("Matriz suma:\n");
    for(int f=0; f<N; f++){
        for(int c=0; c<N; c++){
            printf("%d  ", M3[f][c]);
        }
        printf("\n");
    }

    return 0;
}