/* pilaArray.h */

#define CAPACIDAD 15

int pila[CAPACIDAD];
int cima = -1;

void apilar(int);
int desapilar();
void vaciarPila();
int size();
int estaVacia();
int primero();