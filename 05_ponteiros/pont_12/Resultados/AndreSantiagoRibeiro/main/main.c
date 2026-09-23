#include <stdio.h>
#include "vetor.h"

int Soma(int a, int b);
int Multiplicacao(int a, int b);

int main(){
    Vetor v;
    LeVetor(&v);
    printf("Soma: %d\n", AplicarOperacaoVetor(&v, Soma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&v, Multiplicacao));

    return 0;
}

int Soma(int a, int b){
    return a + b;
}
int Multiplicacao(int a, int b){
    return a*b;
}