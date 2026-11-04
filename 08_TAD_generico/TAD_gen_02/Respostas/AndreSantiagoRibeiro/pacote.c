#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacote.h"

struct pacote {
    void* vetor;
    int tipo;
    int tam;
    int bytes;
};

tPacote* CriaPacote(Type type, int numElem){
    tPacote* p = (tPacote*) malloc(sizeof(tPacote));
    p->tam = numElem;
    p->tipo = type;
    if(type == INT){
        p->vetor = malloc(numElem * sizeof(int));
        p->bytes = sizeof(int);
    }
    else if(type == CHAR){
        p->vetor = malloc(numElem * sizeof(char));
        p->bytes = sizeof(char);
    }

    return p;
}

void DestroiPacote(tPacote* pac){
    free(pac->vetor);
    free(pac);
}

void LePacote(tPacote* pac){
    int i;
    if(pac->tipo == INT) {
        for(i = 0; i < pac->tam; i++){
            scanf("%d ", ((int*)pac->vetor)[i]);
        }
    }
    else if(pac->tipo == CHAR) {
        for(i = 0; i < pac->tam; i++){
            scanf("%c", ((int*)pac->vetor)[i]);
        }
    }
}