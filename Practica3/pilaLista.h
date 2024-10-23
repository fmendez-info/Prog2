/* pilaLista.h */

typedef struct nodo{
    int dato;
    struct nodo* sig;
} pila;

void apilar(pila**, int);
int desapilar(pila**);
void vaciarPila(pila**);
int size(pila**);
int estaVacia(pila**);
int cima(pila*);