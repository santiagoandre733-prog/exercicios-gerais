#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

char *CriaVetor(int tamanho){
    char *v = (char*) malloc(tamanho * sizeof(char));
    int i;
    for(i = 0; i < tamanho; i++){
        v[i] = '_';
    }

    return v;
}

void LeVetor(char *vetor, int tamanho){
    while(tamanho > 0){
        scanf("%c", vetor);
        vetor++;
        tamanho--;
    }
    scanf("*[^\n]\n");
}

void ImprimeString(char *vetor, int tamanho){
    while(tamanho > 0){
        printf("%c", *vetor);
        vetor++;
        tamanho--;
    }
    
    printf("\n");
}

void LiberaVetor(char *vetor){
    free(vetor);
}