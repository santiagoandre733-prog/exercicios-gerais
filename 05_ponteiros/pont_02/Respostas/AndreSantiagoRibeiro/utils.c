#include "utils.h"
#include <stdio.h>

void LeIntervalo(int * m, int * n){
    scanf("%d %d ", m, n);
}

int EhPrimo(int n){
    int i;
    if(n <= 2){
        return 1;
    }
    for(i = 2; i <= n/2; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    int i, flag = 0;
    for(i = m; i <= n; i++){
        if(EhPrimo(i)){
            if(flag){
                *maior = i;
            }
            else {
                *menor = i;
                *maior = i;
                flag = 1;
            }
        }
    }
}