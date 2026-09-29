#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

char *CriaVetorTamPadrao(){
    char *v = (char*) malloc((TAM_PADRAO + 1) * sizeof(char));
    int i;
    for(i = 0; i < TAM_PADRAO; i++){
        v[i] = '_';
    }
    v[i] = 0;

    return v;
}

char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){
    char* temp = (char*) realloc(vetor, (tamanhoantigo + TAM_PADRAO + 1)*sizeof(char));
    int i;
    for(i = tamanhoantigo; i < (tamanhoantigo + TAM_PADRAO); i++){
        temp[i] = '_';
    }
    temp[i] = 0;

    return temp;
}

char* LeVetor(char *vetor, int *tamanho){
    int i = 0;
    char c;
    while(1){
        scanf("%c", &c);
        if(c == '\n'){
            break;
        }

        if(i == *tamanho){
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }
        vetor[i] = c;
        i++;
    }

    return vetor;
}

void ImprimeString(char *vetor){
    printf("%s", vetor);
}

void LiberaVetor(char *vetor){
    free(vetor);
}