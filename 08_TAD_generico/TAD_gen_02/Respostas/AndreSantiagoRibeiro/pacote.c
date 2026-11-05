#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacote.h"

struct pacote {
    void* vetor;
    int tipo;
    int tam;
    int bytes;
    int soma;
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
    scanf(" ");
    if(pac->tipo == INT) {
        for(i = 0; i < pac->tam; i++){
            int n;
            scanf("%d ", &n);
            //((int*)pac->vetor)[i] = n;
            memcpy(pac->vetor + i*pac->bytes, &n, pac->bytes);
        }
    }
    else if(pac->tipo == CHAR) {
        for(i = 0; i < pac->tam; i++){
            char c;
            scanf("%c", &c);
            //((char*)pac->vetor)[i] = c;
            memcpy(pac->vetor + i*pac->bytes, &c, pac->bytes);
        }
        //scanf(" ");
    }
    //scanf("%[^\n]\n");
}

void ImprimePacote(tPacote* pac){
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->soma);
    if(pac->tipo == INT){
        int i;
        for(i = 0; i < pac->tam; i++){
            printf("%d", ((int*)pac->vetor)[i]);
            if(i < pac->tam - 1) printf(" ");
        }
    }
    else if(pac->tipo == CHAR){
        int i;
        for(i = 0; i < pac->tam; i++){
            printf("%c", ((char*)pac->vetor)[i]);
        }
    }
    printf("\n");
}

void CalculaSomaVerificacaoPacote(tPacote* pac){
    pac->soma = 0;
    int i;
    if(pac->tipo == INT){
        for(i = 0; i < pac->tam; i++){
            pac->soma += ((int*)pac->vetor)[i];
        }
    }
    else if(pac->tipo == CHAR){
        for(i = 0; i < pac->tam; i++){
            pac->soma += ((char*)pac->vetor)[i];
        }
    }
}