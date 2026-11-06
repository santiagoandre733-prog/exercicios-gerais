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
    return mat->matriz + (linha*mat->colunas + coluna)*mat->numBytes;
}

void AtribuiElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna, void* elem){
    memcpy(mat->matriz + (linha*mat->colunas + coluna)*mat->numBytes, elem, mat->numBytes);
}

void ImprimirMatrizGenerica(tMatrizGenerica * mat, void (imprime_elemento(void*))){
    int i, j;
    for(i = 0; i < mat->linhas; i++){
        for(j = 0; j < mat->colunas; j++){
            imprime_elemento(mat->matriz + (i*mat->colunas + j)*mat->numBytes);
            printf(" ");
        }
        printf("\n");
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
    tMatrizGenerica* mult = CriaMatrizGenerica(mat1->linhas, mat2->colunas, numByteTarget);
    int i, j, k;
    for(i = 0; i < mat1->linhas; i++){
        for(j = 0; j < mat2->colunas; j++){
            void *mult0;
            void *mult1;
            void *soma;
            mult0 = multi_elem(ObtemElementoMatrizGenerica(mat1, i, 0), ObtemElementoMatrizGenerica(mat2, 0, j));
            mult1 = multi_elem(ObtemElementoMatrizGenerica(mat1, i, 1), ObtemElementoMatrizGenerica(mat2, 1, j));
            soma = soma_elem(mult0, mult1);
            free(mult0);
            free(mult1);
            for(k = 2; k < mat1->colunas; k++){
                mult0 = multi_elem(ObtemElementoMatrizGenerica(mat1, i, k), ObtemElementoMatrizGenerica(mat2, k, j));
                void *novaSoma = soma_elem(soma, mult0);

                free(soma);
                free(mult0);

                soma = novaSoma;
                free(mult0);
            }

            AtribuiElementoMatrizGenerica(mult, i, j, soma);
            free(soma);
        }
    }

    return mult;
}

tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*)){
    tMatrizGenerica *matN = CriaMatrizGenerica(mat2->linhas, mat2->colunas, novoNumByteElem);
    int i, j;
    for(i = 0; i < matN->linhas; i++){
        for(j = 0; j < matN->colunas; j++){
            void* elem = converte_elem(ObtemElementoMatrizGenerica(mat2, i, j));
            AtribuiElementoMatrizGenerica(matN, i, j, elem);
            free(elem);
        }
    }
    return matN;
}