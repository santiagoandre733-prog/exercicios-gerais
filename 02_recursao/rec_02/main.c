#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos);
int EhPar(int n);

int main(){
    int qtdN, qtdVet;
    int* vet;
    int n, i, j;
    
    scanf("%d ", &qtdVet);

    for(i = 0; i < qtdVet; i++){

        scanf("%d ", &qtdN);
        for(j = 0; j < qtdN; j++){
            scanf("%d ", &n);
            vet[j] = n;
        }

        printf("%d\n", SomaElementosPares(vet, qtdN));
    }
}

int SomaElementosPares(int* vet, int numElementos){
    if(numElementos == 0){
        return 0;
    }

    if(EhPar(vet[numElementos - 1])){
        return vet[numElementos - 1] + SomaElementosPares(vet, numElementos - 1);
    }
    
    return SomaElementosPares(vet, numElementos - 1);
    
}

int EhPar(int n){
    return (n%2 == 0);
}