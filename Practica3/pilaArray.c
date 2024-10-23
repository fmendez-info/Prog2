/* pilaArray.c */

#include <stdio.h>
#include "pilaArray.h"

void apilar(int elemento){
    if(size()==CAPACIDAD) {printf("Pila Completa\n"); return;}
    cima++;
    pila[cima]=elemento;
    return;
}

int desapilar(){
    if(estaVacia()) {printf("Pila Vacia\n"); return;}
    cima--;
    return pila[cima+1];
}

void vaciarPila(){
    cima = -1;
    return;
}

int size(){
    return cima + 1;
}

int estaVacia(){
    return cima == -1;
}

int primero(){
    if(estaVacia) {printf("Pila Vacia\n"); return;}
    return pila[cima];
}

int main(){

    return 0;
}