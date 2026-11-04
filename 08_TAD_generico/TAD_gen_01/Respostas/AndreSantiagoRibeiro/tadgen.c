#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadgen.h"

struct generic {
    void *vetor;
    int bytes;
    int tam;
    int tipo;
};

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *g = (tGeneric*) malloc(sizeof(tGeneric));
    g->tam = numElem;
    if(type == INT){
        g->bytes = sizeof(int);
        g->tipo = INT;
    }
    else if(type == FLOAT){
        g->bytes = sizeof(float);
        g->tipo = FLOAT;
    }
    g->vetor = malloc(g->tam * g->bytes);

    return g;
}

void DestroiGenerico(tGeneric* gen){
    free(gen->vetor);
    free(gen);
}

void LeGenerico(tGeneric* gen){
    int i;
    printf("\nDigite o vetor:\n");
    if(gen->tipo == INT){
        int n;
        for(i = 0; i < gen->tam; i++){
            scanf("%d ", &n);
            memcpy((int*)gen->vetor + i, &n, gen->bytes);
        }
    }
    else if(gen->tipo == FLOAT){
        float n;
        for(i = 0; i < gen->tam; i++){
            scanf("%f ", &n);
            memcpy((float*)gen->vetor + i, &n, gen->bytes);
        }
    }
}

void ImprimeGenerico(tGeneric* gen){
    int i;
    if(gen->tipo == INT){
        for(i = 0; i < gen->tam; i++){
            printf("%d ", *((int*)gen->vetor + i));
        }
    }
    else if(gen->tipo == FLOAT){
        for(i = 0; i < gen->tam; i++){
            printf("%.2f ", *((float*)gen->vetor + i));
        }
    }
    printf("\n");
}