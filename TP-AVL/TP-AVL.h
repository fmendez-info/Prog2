/* TP-AVL.h */

typedef struct nodo{
    int dato;
    int alt;
    struct nodo* hi;
    struct nodo* hd;
} Nodo;

int altura(Nodo*);
int factorBalanceo(Nodo*);
Nodo* insertar(Nodo*, int);
Nodo* obtenerMinimo(Nodo*);
Nodo* eliminar(Nodo*, int);
Nodo* crearNodo(int);
void actualizarAltura(Nodo*);
int esMiembro(Nodo*, int);

Nodo* rotacionD(Nodo*);
Nodo* rotacionI(Nodo*);
Nodo* rotacionID(Nodo*);
Nodo* rotacionDI(Nodo*);

Nodo* insertarElemento(Nodo*);
Nodo* eliminarElemento(Nodo*);

typedef struct nodoCola {
    Nodo* nodoArbol;
    int nivel;
    struct nodoCola* sig;
} NodoCola;

typedef struct cola{
    NodoCola* primero; //puntero al primer elemento (donde desencolar)
    NodoCola* ultimo; //puntero al ultimo elemento (donde encolar)
} Cola;

Cola* crearCola();
int colaVacia(Cola*);
void encolar(Cola*, Nodo*, int);
NodoCola* desencolar(Cola*);
void recorridoHorizontal(Nodo*);
void imprimirPorNiveles(Nodo*);