#include "vetor.h"
#include <stdio.h>

void LeVetor(Vetor *vetor){
    scanf("%d ", &vetor->tamanhoUtilizado);
    int i;
    for(i = 0; i < vetor->tamanhoUtilizado; i++){
        scanf("%d ", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int i, resultado = op(vetor->elementos[0], vetor->elementos[1]);
    for(i = 2; i < vetor->tamanhoUtilizado; i++){
        resultado = op(resultado, vetor->elementos[i]);
    }

    return resultado;
}