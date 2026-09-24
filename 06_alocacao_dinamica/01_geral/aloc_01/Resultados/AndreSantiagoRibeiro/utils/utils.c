#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int *CriaVetor(int tamanho){
    int *v = (int*) malloc (tamanho * sizeof(int));
    if(v == NULL){
        printf("ERRO\n");
        exit(1);
    }
    return v;
}

void LeVetor(int *vetor, int tamanho){
    while(tamanho > 0){
        scanf("%d ", vetor);
        vetor++;
        tamanho--;
    }
}

float CalculaMedia(int *vetor, int tamanho){
    float soma = 0;
    int i;
    for(i = 0; i < tamanho; i++){
        soma += vetor[i];
    }

    return soma / tamanho;
}

void LiberaVetor(int *vetor){
    free(vetor);
}