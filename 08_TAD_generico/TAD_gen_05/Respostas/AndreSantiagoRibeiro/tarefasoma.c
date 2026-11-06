#include <stdio.h>
#include <stdlib.h>
#include "tarefasoma.h"

struct soma {
    float n1, n2;
};

tSoma* CriaTarefaSoma(float n1, float n2){
    tSoma* soma = malloc(sizeof(tSoma));
    soma->n1 = n1;
    soma->n2 = n2;
    return soma;
}

void ExecutaTarefaSoma(void *sum){
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", ((tSoma*)sum)->n1, ((tSoma*)sum)->n2, ((tSoma*)sum)->n1 + ((tSoma*)sum)->n2);
}

void DestroiTarefaSoma(void *sum){
    free((tSoma*)sum);
}