#include "vetor.h"
#include <stdio.h>

void LeVetor(Vetor *vetor){
    scanf("%d ", vetor->tamanhoUtilizado);
    int i;
    for(i = 0; i < vetor->tamanhoUtilizado; i++){
        scanf("%d ", vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int i, resultado = 0;
    for(i = 0; i < vetor->tamanhoUtilizado; i++){
        resultado = op(resultado, vetor->elementos[i]);
    }

    return resultado;
}