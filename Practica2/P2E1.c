#include <stdio.h>

typedef struct tiempo{
    int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

int compara_tiempos(Tiempo*,Tiempo*);
void imprime_tiempo(Tiempo);

int main(){
    Tiempo t1={2002, 5, 6, 22, 10, 2};
    Tiempo t2={2002, 5, 6, 22, 10, 5};
    printf("%d\n", t1.anio);
    imprime_tiempo(t1);
    imprime_tiempo(t2);
    printf("%d\n", compara_tiempos(&t1, &t2));
}

// primer intento de algoritmo, largo y repetitivo
/* int compara_tiempos(Tiempo* t1, Tiempo* t2){
    if(t1->anio < t2->anio) return 1;
    if(t1->anio > t2->anio) return -1;
    if(t1->mes < t2->mes) return 1;
    if(t1->mes > t2->mes) return -1;
    if(t1->dia < t2->dia) return 1;
    if(t1->dia > t2->dia) return -1;
    if(t1->hora < t2->hora) return 1;
    if(t1->hora > t2->hora) return -1;
    if(t1->minuto < t2->minuto) return 1;
    if(t1->minuto > t2->minuto) return -1;
    if(t1->segundo < t2->segundo) return 1;
    if(t1->segundo > t2->segundo) return -1;
    return 0;
} */

// otra alternativa mas concisa, recorre los componentes de los tiempos con un for
int compara_tiempos(Tiempo* t1, Tiempo* t2) {
    int t1_[] = {t1->anio, t1->mes, t1->dia, t1->hora, t1->minuto, t1->segundo};
    int t2_[] = {t2->anio, t2->mes, t2->dia, t2->hora, t2->minuto, t2->segundo};

    for (int i = 0; i < 6; i++) {
        if (t1_[i] < t2_[i]) return 1;
        if (t1_[i] > t2_[i]) return -1;
    }
    return 0;
}

void imprime_tiempo(Tiempo t){
    printf("%02d/%02d/%04d %02d:%02d:%02d\n", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}