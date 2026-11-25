#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

struct Vector {
    DataType *vetor;
    int tamanho;
};

Vector *VectorConstruct(){
    Vector *v = calloc(1, sizeof(Vector));
    return v;
}

void VectorPushBack(Vector *v, DataType val){
    v->vetor = realloc(v->vetor, (v->tamanho + 1)*sizeof(DataType));
    v->vetor[v->tamanho] = val;
    v->tamanho += 1;
}

void VectorRemove(Vector *v, int i){
    int j;
    for(j = i; j < v->tamanho - 1; j++){
        VectorSwap(v, j, j + 1);
    }
    v->vetor = realloc(v->vetor, (v->tamanho - 1)*sizeof(DataType));
}

DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
}

int VectorSize(Vector *v){
    return v->tamanho;
}

void VectorSwap(Vector *v, int i, int j){
    DataType temp;
    temp = v->vetor[i];
    v->vetor[i] = v->vetor[j];
    v->vetor[j] = temp;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    int i;
    for(i = 0; i < v->tamanho; i++){
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}