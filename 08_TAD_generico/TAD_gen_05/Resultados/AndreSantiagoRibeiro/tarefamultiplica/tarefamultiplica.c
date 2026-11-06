#include <stdio.h>
#include <stdlib.h>
#include "tarefamultiplica.h"

struct mult {
    float n1, n2;
};

tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult* mult = malloc(sizeof(tMult));
    mult->n1 = n1;
    mult->n2 = n2;
    return mult;
}

void ExecutaTarefaMultiplicar(void *mult){
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", ((tMult*)mult)->n1, ((tMult*)mult)->n2, ((tMult*)mult)->n1*((tMult*)mult)->n2);
}

void DestroiTarefaMultiplicar(void *mult){
    free((tMult*)mult);
}