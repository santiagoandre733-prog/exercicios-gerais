#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void LiberaDefesa(tDefesa defesa){
    free(defesa);
}

int VerificaSeDentroArea(tDefesa defesa, float x, float y){
    if(defesa->tipo == CIRCULO){
        int distancia = sqrt(pow(defesa->x - x, 2) + pow(defesa->y - y, 2));
        return distancia < defesa->tamanho;
    }
    else {
        int n = defesa->tamanho / sqrt(2);
        int distx = defesa->x - x;
        int disty = defesa->y - y;
        if(distx < 0) distx = -distx;
        if(disty < 0) disty = -disty;

        return (distx < n) && (disty < n);
    }
}

void UsaDefesa(tDefesa defesa){
    defesa->quantidade -= 1;
}

float GetDefesaPoder(tDefesa defesa){
    return defesa->poder;
}

int PodeDefender(tDefesa defesa){
    return defesa->quantidade > 0;
}