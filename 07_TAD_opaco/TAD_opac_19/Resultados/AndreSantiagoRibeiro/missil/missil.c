#include <stdio.h>
#include <stdlib.h>
#include "missil.h"

struct missil {
    char nome[MAX_TAM];
    float x;
    float y;
    float poder;
};

tMissil LeMissil(){
    tMissil m = (tMissil) malloc(sizeof(struct missil));
    scanf("%s %f %f %f ", m->nome, &m->x, &m->y, &m->poder);
    return m;
}

void ImprimeMissil(tMissil missil){
    printf("M-%s: %.2f\n", missil->nome, missil->poder);
}

void LiberaMissil(tMissil missil){
    free(missil);
}

float GetMissilY(tMissil missil){
    return missil->y;
}

float GetMissilX(tMissil missil){
    return missil->x;
}

float GetMissilPoder(tMissil missil){
    return missil->poder;
}

void ReduzPoder(tMissil missil, float valor){
    missil->poder -= valor;
    if(missil->poder < 0) missil->poder = 0;
}