#include "utils.h"
#include <stdio.h>

void LeNumeros(int *array, int tamanho){
    while(tamanho){
        scanf("%d ", array);
        array++;
        tamanho--;
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    int soma = 0;
    int flag = 0;
    int tamOG = tamanho;
    while(tamanho){
        if(!flag){
            *maior = *array;
            *menor = *array;
            flag = 1;
        }
        else {
            if(*array < *menor){
                *menor = *array;
            }
            if(*array > *maior){
                *maior = *array;
            }
        }

        soma += *array;
        array++;
        tamanho--;
    }

    *media = (float)soma / tamOG;
}