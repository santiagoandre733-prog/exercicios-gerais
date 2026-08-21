#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

int main(){
    int numeroProcurado, qtdN, i, j, qtdVet;
    int* vet;

    scanf("%d ", &qtdVet);

    for(i = 0; i < qtdVet; i++){
        scanf("%d ", &numeroProcurado);
        scanf("%d ", &qtdN);
        for(j = 0; j < qtdN; j++){
            scanf("%d ", &vet[j]);
        }

        printf("%d\n", ContaOcorrencias(vet, qtdN, numeroProcurado));
    }

    return 0;
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    if(numElementos == 0){
        return 0;
    }

    if(vet[numElementos - 1] == numeroProcurado){
        return 1 + ContaOcorrencias(vet, numElementos - 1, numeroProcurado);
    }

    return ContaOcorrencias(vet, numElementos - 1, numeroProcurado);
}