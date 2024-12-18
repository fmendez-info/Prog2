// Trabajo final programacion 2 Martin Mercado

#include <stdio.h>
#include <stdlib.h>

#define MAX(X,Y) ((X) >= (Y) ? (X) : (Y))

int numero_digitos(int num){
    int contador = 0;

    if(num == 0){
        return 1;
    }

    if(num < 0){
        num = -num;
    }

    while(num > 0){
        num = num/10;
        contador++;
    }

    return contador;

}

typedef struct Nodo{
    int dato;
    int altura;
    struct Nodo * hijo_izq;
    struct Nodo * hijo_der;
}nodo;

typedef struct Nodo_cola{
    struct Nodo * nodo;
    int nivel;
    struct Nodo_cola * siguiente;
}nodo_cola;

typedef struct Cola{
    struct Nodo_cola * frente;
    struct Nodo_cola * final;
}cola;

cola * crear_cola(){

    cola * nueva_cola = malloc(sizeof(cola));

    nueva_cola->frente = nueva_cola->final = NULL;
    
    return nueva_cola;
}

void encolar(cola * cola, nodo * nodo, int nivel){

    nodo_cola * nuevo_nodo_cola = malloc(sizeof(nodo_cola));
    
    nuevo_nodo_cola->nodo = nodo;

    nuevo_nodo_cola->nivel = nivel;

    nuevo_nodo_cola->siguiente = NULL;

    if(cola->final != NULL){
        cola->final->siguiente = nuevo_nodo_cola;
    }else{
        cola->frente = nuevo_nodo_cola;
    }
    cola->final = nuevo_nodo_cola;

}

nodo_cola * desencolar(cola * cola){

    if(cola->frente == NULL){
        return NULL;
    }

    nodo_cola * nodo_a_eliminar = cola->frente;

    cola->frente = nodo_a_eliminar->siguiente;

    if(cola->frente == NULL){
        cola->final = NULL;
    }

    return nodo_a_eliminar;

}

int cola_esvacia(cola * cola){
    return cola->frente == NULL;    //true devuelve 1, false 0
}

void imprimir_arbol(nodo * raiz, int nivel, int raiz_der_izq) {

    //raiz_der_izq == 0-> raiz, == 1 -> hder, == -1 -> hizq

    if (raiz == NULL) {
        printf("\nEl arbol esta vacio.\n\n");
        return;
    }

    if(nivel == 0){
        printf("Su arbol es:\n\n");
    }
    
    if(raiz->hijo_der != NULL){
        imprimir_arbol(raiz->hijo_der, nivel + 1, 1);
    }

    for (int i = 0; i < nivel; i++) {
        printf("\t");  //Imprime una tabulación por cada nivel de profundidad
    }

    if(raiz_der_izq == 1){
        printf("\u250C");
    } else if(raiz_der_izq == -1){
        printf("\u2514");
    }

    printf("%d", raiz->dato);

    if(raiz->hijo_der != NULL || raiz->hijo_izq != NULL){

        int num_digitos = numero_digitos(raiz->dato);
        
        for(int i = 0; i< (8 - num_digitos);i++){
            printf("-");
        }
    }

    printf("\n");

    if(raiz->hijo_izq != NULL){
        imprimir_arbol(raiz->hijo_izq, nivel + 1, -1);
    }
}

int altura(nodo * nodo){
    
    if((nodo) == NULL){
        return 0;
    }
    return nodo->altura;
}

void actualizar_altura (nodo * nodo){

    if(nodo == NULL){
        return;
    }

    int altura_izq = (nodo->hijo_izq != NULL) ? nodo->hijo_izq->altura : 0;
    int altura_der = (nodo->hijo_der != NULL) ? nodo->hijo_der->altura : 0;

    nodo->altura = MAX(altura_izq, altura_der) + 1;

}

int factor_balanceo (nodo * nodo){
    
    if(nodo == NULL){
        return 0;
    }
    
    return (altura(nodo->hijo_izq) - altura(nodo->hijo_der));
}

nodo * rotacion_derecha(nodo * y){

    nodo * x = y->hijo_izq;
    nodo * T = x->hijo_der;

    x->hijo_der = y;
    y->hijo_izq = T;

    actualizar_altura(y);
    actualizar_altura(x);

    return x;
}

nodo * rotacion_izquierda (nodo * x){

    nodo * y = x->hijo_der;
    nodo * T = y->hijo_izq;

    y->hijo_izq = x;
    x->hijo_der = T;

    actualizar_altura (x);
    actualizar_altura (y);

    return y;
}

nodo * rotacion_izquierda_derecha(nodo * nodo){

    nodo->hijo_izq = rotacion_izquierda(nodo->hijo_izq);
    return rotacion_derecha(nodo);

}

nodo * rotacion_derecha_izquierda(nodo * nodo){

    nodo->hijo_der = rotacion_derecha(nodo->hijo_der);
    return rotacion_izquierda(nodo);

}

nodo * insertar(nodo * raiz, int valor){

    if(raiz == NULL){

        raiz = malloc(sizeof(nodo));
        raiz->dato = valor;
        raiz->hijo_der = NULL;
        raiz->hijo_izq = NULL;
        actualizar_altura(raiz);

        return raiz;
    }

    if(valor < raiz->dato){
        raiz->hijo_izq = insertar(raiz->hijo_izq, valor);

    } else if(valor > raiz->dato){
        raiz->hijo_der = insertar(raiz->hijo_der, valor);
    
    }else{
        return raiz;
    }

    actualizar_altura(raiz);

    int balance = factor_balanceo(raiz);

    if(balance > 1 && valor < raiz->hijo_izq->dato){
        return rotacion_derecha(raiz);
    }

    if(balance < -1 && valor > raiz->hijo_der->dato){
        return rotacion_izquierda(raiz);
    }

    if(balance > 1 && valor > raiz->hijo_izq->dato){
        return rotacion_izquierda_derecha(raiz);
    }

    if(balance <-1 && valor < raiz->hijo_der->dato){
        return rotacion_derecha_izquierda(raiz);
    }

    return raiz;

}

nodo * obtener_minimo(nodo * raiz){

    if(raiz == NULL){
        return raiz;
    }

    while(raiz->hijo_izq != NULL){
        raiz = raiz->hijo_izq;
    }
    return raiz;
}

nodo * eliminar(nodo * raiz, int valor){

    if(raiz == NULL){
        printf("El arbol esta vacio, no se puede eliminar un nodo.\n");
        return raiz;
    }

    if(valor < raiz->dato){
        raiz->hijo_izq = eliminar(raiz->hijo_izq, valor);
    }else if(valor > raiz->dato){
        raiz->hijo_der = eliminar(raiz->hijo_der, valor);
    }else{
    
        if(raiz->hijo_izq == NULL || raiz->hijo_der == NULL){
            
            nodo * temp = (raiz->hijo_izq != NULL) ? raiz->hijo_izq : raiz->hijo_der;
            free(raiz);

            return temp;

        }else{
            nodo * sucesor = obtener_minimo(raiz->hijo_der);
            raiz->dato = sucesor->dato;
            raiz->hijo_der = eliminar(raiz->hijo_der, sucesor->dato);
        }
    }

    if(raiz == NULL){
        return raiz;
    }

    actualizar_altura(raiz);

    int balance = factor_balanceo(raiz);

    if(balance > 1 && factor_balanceo(raiz->hijo_izq) >= 0){
        return rotacion_derecha(raiz);
    }

    if(balance > 1 && factor_balanceo(raiz->hijo_izq) < 0){
        return rotacion_izquierda_derecha(raiz);
    }  

    if(balance < -1 && factor_balanceo(raiz->hijo_der) <= 0){
        return rotacion_izquierda(raiz);
    }

    if(balance <- 1 && factor_balanceo(raiz->hijo_der) > 0){
        return rotacion_derecha_izquierda(raiz);
    }

    return raiz;

}

int miembro(nodo *raiz, int valor) {
   
    if(raiz == NULL){
        return 0;
    }

    if(raiz->dato == valor){
        return 1;
    }

    if(miembro(raiz->hijo_izq, valor)){
        return 1;
    }

    if(miembro(raiz->hijo_der, valor)){
        return 1;
    }

    return 0;

}

void imprimir_niveles(nodo * raiz){

    if(raiz == NULL){
        printf("\nEl arbol esta vacio.\n\n");
        return;
    }

    printf("\n");

    int nivel_actual = -1;

    cola * cola = crear_cola();
    
    encolar(cola, raiz, 0);

    while(!cola_esvacia(cola)){

        nodo_cola * nodo_cola_procesado = desencolar(cola);

        nodo * nodo_arbol = nodo_cola_procesado->nodo;

        int nivel = nodo_cola_procesado->nivel;

        if(nivel != nivel_actual){
            if(nivel_actual != -1){
                printf("\n");
            }
            nivel_actual = nivel;
            printf("Nivel %d: ", nivel);
        }

        printf("%d ", nodo_arbol->dato);

        if(nodo_arbol->hijo_izq != NULL){
            encolar(cola, nodo_arbol->hijo_izq, nivel + 1);
        }

        if(nodo_arbol->hijo_der != NULL){
            encolar(cola, nodo_arbol->hijo_der, nivel + 1);
        }

        free(nodo_cola_procesado);

    }

    free(cola);

    printf("\n\n");
}

int arbol_esta_balanceado(nodo * raiz){

    if(raiz == NULL){
        return 1;
    }

    int balance = factor_balanceo(raiz);

    if(balance > 1 || balance < -1){
        return 0;
    }

    int izq_balanceado = arbol_esta_balanceado(raiz->hijo_izq);

    int der_balanceado = arbol_esta_balanceado(raiz->hijo_der);

    return izq_balanceado && der_balanceado;
}

int main(){

    nodo * raiz_arbol = NULL;

    int opcion, valor;

    while(1){

        printf("Opciones:\n\
        \n0: Salir\
        \n1: Insertar\
        \n2: Eliminar\
        \n3: Mostrar arbol\
        \n4: Mostrar niveles del arbol\n\
        \nElija una opcion: ");

        while(scanf("%d", &opcion) != 1 || opcion > 4 || opcion < 0){
            printf("Error, intente de nuevo: ");
            while(getchar()!='\n'){}
        }

        if(opcion == 0){
            printf("\nPrograma terminado.\n");
            break;
        }

        if(opcion == 1){
            printf("\nIngrese un valor a insertar: ");
            scanf(" %d", &valor);
            raiz_arbol = insertar(raiz_arbol, valor);
            printf("\n");
            
            imprimir_arbol(raiz_arbol, 0, 0);
            printf("\n");

            if(arbol_esta_balanceado(raiz_arbol)){
                printf("El arbol esta correctamente balanceado.\n\n");
            }else{
                printf("El arbol NO esta correctamente balanceado.\n\n");
            }
        }

        if(opcion == 2){

            if(raiz_arbol == NULL){
                printf("\nEl arbol esta vacio, no se puede eliminar un nodo.\n\n");
                continue;
            }

            printf("\nIngrese un valor a eliminar: ");
            scanf(" %d", &valor);
            printf("\n");
            
            if(!miembro(raiz_arbol ,valor)){
                printf("El valor ingresado no es miembro del arbol.\n\n");
                imprimir_arbol(raiz_arbol,0, 0);
                printf("\n");
                continue;
            }

            raiz_arbol = eliminar(raiz_arbol, valor);
            imprimir_arbol(raiz_arbol,0,0);
            printf("\n");

            if(arbol_esta_balanceado(raiz_arbol)){
                printf("El arbol esta correctamente balanceado.\n\n");
            }else{
                printf("El arbol NO esta correctamente balanceado.\n\n");
            }
        }

        if(opcion == 3){
            imprimir_arbol(raiz_arbol, 0, 0);
        }

        if(opcion == 4){
            imprimir_niveles(raiz_arbol);
        }

    }

    return 0;
}