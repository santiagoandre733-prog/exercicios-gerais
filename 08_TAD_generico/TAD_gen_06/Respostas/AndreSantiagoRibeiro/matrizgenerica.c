#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizgenerica.h"

struct matrizgenerica {
    void *matriz;
    int linhas, colunas;
    int numBytes;
};

tMatrizGenerica * CriaMatrizGenerica(int linhas, int colunas, int numByteElem){
    tMatrizGenerica *m = malloc(sizeof(tMatrizGenerica));
    m->linhas = linhas;
    m->colunas = colunas;
    m->numBytes = numByteElem;
    m->matriz = malloc(linhas*colunas*numByteElem);

    return m;
}

void DestroiMatrizGenerica(tMatrizGenerica * mat){
    free(mat->matriz);
    free(mat);
}

int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica * mat){
    return mat->linhas;
}

int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica * mat){
    return mat->colunas;
}

void * ObtemElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna){
    void* elem;
    memcpy(elem, mat->matriz + (linha*mat->colunas + coluna)*mat->numBytes, mat->numBytes);
    return elem;
}

void AtribuiElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna, void* elem){
    memcpy(mat->matriz + (linha*mat->colunas + coluna)*mat->numBytes, elem, mat->numBytes);
}

void ImprimirMatrizGenerica(tMatrizGenerica * mat, void (imprime_elemento(void*))){
    int i, j;
    for(i = 0; i < mat->linhas; i++){
        for(j = 0; j < mat->colunas; j++){
            imprime_elemento(mat->matriz + (i*mat->colunas + j)*mat->numBytes);
        }
    }
}

tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat){
    tMatrizGenerica *trans = CriaMatrizGenerica(mat->colunas, mat->linhas, mat->numBytes);
    int i, j;
    for(i = 0; i < mat->linhas; i++){
        for(j = 0; j < mat->colunas; j++){
            AtribuiElementoMatrizGenerica(trans, j, i, ObtemElementoMatrizGenerica(mat, i, j));
        }
    }

    return trans;
}

tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*)){
    tMatrizGenerica* mult = CriaMatrizGenerica
}