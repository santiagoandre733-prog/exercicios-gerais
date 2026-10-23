#include <stdio.h>
#include <stdlib.h>
#include "defesa.h"

struct defesa {
    char nome[MAX_TAM];
    char tipo;
    float x, y;
    float tamanho;
    float poder;
    int quantidade;
};

tDefesa LeDefesa(){
    tDefesa d = (tDefesa) malloc(sizeof(struct defesa));
    scanf("%s %f %f %c %f %f %d ", d->nome, &d->x, &d->y, &d->tipo, &d->tamanho, &d->poder, &d->quantidade);
    return d;
}

void ImprimeDefesa(tDefesa defesa){
    printf("D-%s: %d\n", defesa->nome, defesa->quantidade);
}