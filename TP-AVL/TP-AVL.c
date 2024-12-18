/* TP-AVL.c */

#include <stdio.h>
#include <stdlib.h>
#include "TP-AVL.h"

int main(){

    Nodo* nodo = NULL;
    int opcion, valor;

    do{
        printf("Elija una opcion o 0 para terminar:\n");
        printf("1- Insertar un elemento\n");
        printf("2- Eliminar un elemento\n");
        scanf("%d", &opcion);
        while (opcion<0 || opcion >2){
            printf("Error, 1/2 - 0 para terminar: ");
            scanf("%d", &opcion);
        }

        switch(opcion){
            case 1:
                printf("Insertar elemento - ingrese valor: ");
                scanf("%d", &valor);
                nodo = insertar(nodo, valor);
                imprimirPorNiveles(nodo);
                break;
            case 2:
                printf("Eliminar elemento - ingrese valor: ");
                scanf("%d", &valor);
                nodo = eliminar(nodo, valor);
                imprimirPorNiveles(nodo);
                break;
        }
    }while (opcion!=0);

    return 0;
}

int altura(Nodo* n){
    if(n == NULL){
        return 0;
    } else {
        return n->alt;
    }
    //return n==NULL ? 0 : n->alt;
}

int factorBalanceo(Nodo* n){
    //printf("i: %d - %d, d: %d - %d\n", n->hi->dato, n->hi->alt, n->hd->dato, n->hd->alt);
    //printf("alt i: %d, alt d: %d\n", altura(n->hi), altura(n->hd));

    if(n == NULL){
        return 0;
    } else {
        return altura(n->hi) - altura(n->hd);
    }
    //return n==NULL ? 0 : altura(n->hi)-altura(n->hd);
}

Nodo* crearNodo(int valor){
    Nodo* nuevoNodo = (Nodo*) malloc (sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->alt = 1;
    nuevoNodo->hi = NULL;
    nuevoNodo->hd = NULL;
    return nuevoNodo;
}

void actualizarAltura(Nodo* n){
    int altura_izq = altura(n->hi);
    int altura_der = altura(n->hd);
    n->alt = 1 + (altura_izq > altura_der ? altura_izq : altura_der);
}

Nodo* insertar(Nodo* n, int valor){
    //printf("insertar (%d)\n", valor);
    if(n==NULL){
        return crearNodo(valor);
    }
    printf("funcion insertar con nodo(%d)\n", n->dato);

    if(valor < n->dato){
        n->hi = insertar(n->hi, valor);
    } else if(valor > n->dato){
        n->hd = insertar(n->hd, valor);
    } else {
        printf("El valor %d ya esta en el arbol\n", valor);
        return n; //ya existe un nodo con ese valor
    }

    // actualizo la altura del nodo
    actualizarAltura(n);
    printf("Nodo (%d) - Altura (%d)\n", n->dato, n->alt);

    int balance = factorBalanceo(n);
    printf("Factor balance en (%d) = %d\n", n->dato, balance);
    
    if(balance > 1 && valor < n->hi->dato){
        printf("Desbalance I-I\n");
        return rotacionD(n);
    }
    if(balance <-1 && valor > n->hd->dato){
        printf("Desbalance D-D\n");
        return rotacionI(n);
    }
    if(balance > 1 && valor > n->hi->dato){
        printf("Desbalance I-D\n");
        return rotacionID(n);
    }
    if(balance <-1 && valor < n->hd->dato){
        printf("Desbalance D-I\n");
        return rotacionDI(n);
    }

    printf("Arbol balanceado para (%d)\n", n->dato);
    
    return n;
}

int esMiembro(Nodo* n, int valor) {
    if(n == NULL){
        return 0;
    }
    if(n->dato == valor){
        return 1;
    }
    if(esMiembro(n->hi, valor)){
        return 1;
    }
    if(esMiembro(n->hd, valor)){
        return 1;
    }
    return 0;
}

Nodo* obtenerMinimo(Nodo* n){
    printf("obtenerMinimo (%d)\n", n->dato);
    while(n->hi != NULL){
        n = n->hi;
    }
    printf("minimo %d", n->dato);
    return n;
}

Nodo* eliminar(Nodo* n, int valor){
    //printf("eliminar (%d)\n", valor);
    if(n == NULL){
        printf("Arbol Vacio\n");
        printf("El valor %d no esta en el arbol\n", valor);
        return n;
    }
    if(esMiembro(n, valor)){
        if(valor < n->dato){
            //printf("%d < %d\n", valor, n->dato);
            n->hi = eliminar(n->hi, valor);
        } else if(valor > n->dato){
            //printf("%d > %d\n", valor, n->dato);
            n->hd = eliminar(n->hd, valor);
        } else {
            if(n->hi == NULL || n->hd == NULL){
                Nodo* temp = n->hi ? n->hi : n->hd;
                free (n);
                return temp;
            } else {
                Nodo* sucesor = obtenerMinimo(n->hd);
                n->dato = sucesor->dato;
                n->hd = eliminar(n->hd, sucesor->dato);
            }
        }
    } else {
        printf("El valor %d no esta en el arbol\n", valor);
        return n;
    }
    if(n == NULL) return n;

    actualizarAltura(n);

    int balance = factorBalanceo(n);
    //printf("Factor balance en %d = %d\n", n->dato, balance);

    if(balance > 1 && factorBalanceo(n->hi) >=0){
        printf("Desbalance I-I\n");
        return rotacionD(n);
    }
    if(balance > 1 && factorBalanceo(n->hi) < 0){
        printf("Desbalance I-D\n");
        return rotacionID(n);
    }
    if(balance <-1 && factorBalanceo(n->hd) <=0){
        printf("Desbalance D-D\n");
        return rotacionI(n);
    }
    if(balance <-1 && factorBalanceo(n->hd) > 0){
        printf("Desbalance D-I\n");
        return rotacionDI(n);
    }
    return n;
}

Nodo* rotacionD(Nodo* y){
    printf("RotacionD en nodo %d\n", y->dato);
    Nodo* x = y->hi;
    Nodo* T = x->hd;

    x->hd = y;
    y->hi = T;

    actualizarAltura(y);
    actualizarAltura(x);

    return x;
}

Nodo* rotacionI(Nodo* x){
    printf("RotacionI en nodo %d\n", x->dato);
    Nodo* y = x->hd;
    Nodo* T = y->hi;

    y->hi = x;
    x->hd = T;

    actualizarAltura(x);
    actualizarAltura(y);
    
    return y;
}

Nodo* rotacionID(Nodo* n){
    printf("RotacionID\n");
    n->hi = rotacionI(n->hi);
    return rotacionD(n);
}

Nodo* rotacionDI(Nodo* n){
    printf("RotacionDI\n");
    n->hd = rotacionD(n->hd);
    return rotacionI(n);
}

Cola* crearCola(){
    Cola* c = (Cola*) malloc (sizeof(Cola));
    c->primero = NULL;
    c->ultimo = NULL;
    return c;
}

int colaVacia(Cola* c){
    return c->primero == NULL ? 1 : 0;
}

void encolar(Cola* c, Nodo* n, int nivel){
    NodoCola* nuevo = (NodoCola*) malloc (sizeof(NodoCola));
    nuevo->nodoArbol = n;
    nuevo->nivel = nivel;
    nuevo->sig = NULL;

    if(colaVacia(c)){
        c->primero = nuevo;
        c->ultimo = nuevo;
    } else {
        c->ultimo->sig = nuevo;
        c->ultimo = nuevo;
    }
    return;
}

NodoCola* desencolar(Cola* c){
    if(colaVacia(c)){
        return NULL;
    }

    NodoCola* nodoC = c->primero;
    c->primero = nodoC->sig;
    
    if (colaVacia(c)) c->ultimo = NULL;

    return nodoC;
}

/* void recorridoHorizontal(Nodo* n){
    if (n == NULL){
        printf(" X ");
        return;
    }
    Cola* c = crearCola();
    encolar(c,n);

    while (!colaVacia(c)){
        Nodo* actual = desencolar(c);
        printf(" %d ", actual->dato);

        if(actual->hi != NULL){
            encolar(c,actual->hi);
        }
        if(actual->hd != NULL){
            encolar(c,actual->hd);
        }
    }
} */

void imprimirPorNiveles(Nodo *raiz) {
    if (raiz == NULL) {
        printf("Árbol vacío\n");
        return;
    }

    Cola *cola = crearCola();
    encolar(cola, raiz, 0);

    int nivelActual = -1;

    while (!colaVacia(cola)) {
        NodoCola *nodoCola = desencolar(cola);
        Nodo *nodo = nodoCola->nodoArbol;
        int nivel = nodoCola->nivel;

        // Cada vez que se pase al nivel siguiente
        if (nivel != nivelActual) {
            nivelActual = nivel;
            printf("\nNivel %d: ", nivelActual);
        }

        // Imprimir el valor del nodo o "X" si es nulo
        if (nodo == NULL) {
            printf(" X ");
        } else {
            printf("%d ", nodo->dato);
            // Encolar los hijos incluso los nulos
            encolar(cola, nodo->hi, nivel + 1);
            encolar(cola, nodo->hd, nivel + 1);
        }

        free(nodoCola);
    }

    printf("\n");
    free(cola);
    return;
}