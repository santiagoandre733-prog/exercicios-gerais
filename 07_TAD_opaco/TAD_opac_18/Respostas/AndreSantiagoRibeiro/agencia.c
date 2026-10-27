#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "operacao.h"

struct Agencia {
    tConta **contas;
    tOperacao **operacoes;
    int qtdC;
    int qtdO;
};

tAgencia* CriaAgencia(){
    tAgencia* agencia = (tAgencia*) calloc(1, sizeof(tAgencia));
    return agencia;
}

void DestroiAgencia(tAgencia* agencia){
    int i;
    for(i = 0; i < agencia->qtdC; i++){
        DestroiConta(agencia->contas[i]);
    }
    for(i = 0; i < agencia->qtdO; i++){
        DestroiOperacao(agencia->operacoes[i]);
    }
    free(agencia->contas);
    free(agencia->operacoes);
    free(agencia);
}

void LeOperacoes(tAgencia *agencia){
    int n, id;
    float valor;
    scanf("%d ", &n);
    int i;
    agencia->contas = (tConta**) malloc(n * sizeof(tConta*));
    for(i = 0; i < n; i++){
        scanf("%d ", &id);
        if(id <= 0){
            printf("\nDigite um id valido para a conta a ser cadastrada!");
            i--;
        }
        
    }
}