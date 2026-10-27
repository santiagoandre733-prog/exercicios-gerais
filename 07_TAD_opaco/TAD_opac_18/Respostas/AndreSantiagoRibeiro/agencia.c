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
        else if(BuscaContaPorId(agencia, id) != NULL){
            printf("\nEste id ja esta cadastrado na agencia. Digite um id diferente!");
            i--;
        }
        else {
            agencia->contas[i] = CriaConta(id);
            agencia->qtdC += 1;
        }
    }

    scanf("%d ", &n);
    agencia->operacoes = (tOperacao**) malloc(n * sizeof(tOperacao*));
    for(i = 0; i < n; i++){
        tConta *conta;
        scanf("%d %f ", &id, &valor);
        conta = BuscaContaPorId(agencia, id);
        if(conta == NULL){
            printf("\nConta Invalida! Repita a operacao, mas com uma conta valida!");
            i--;
        }
        else {
            agencia->operacoes[i] = CriaOperacao(conta, valor);
            agencia->qtdO += 1;
            AlteraSaldoConta(conta, valor);
        }
    }
}

tConta* BuscaContaPorId(tAgencia *agencia, int id){
    int i;
    for(i = 0; i < agencia->qtdC; i++){
        if(ConfereIdConta(agencia->contas[i], id)){
            return agencia->contas[i];
        }
    }
    return NULL;
}

void ImprimeOperacoesSuspeitas(tAgencia* agencia){
    printf("\nA lista de operações suspeitas:");
    int i;
    for(i = 0; i < agencia->qtdO; i++){
        float valor = ConsultaValorOperacao(agencia->operacoes[i]);
        if(valor >= 20000 || valor <= -20000){
            ImprimeOperacao(agencia->operacoes[i]);
        }
    }
}

void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia* agencia){
    tConta *M1, *M2;
    int i;
    M1 = agencia->contas[0];
    M2 = agencia->contas[0];
    for(i = 1; i < agencia->qtdC; i++){
        if(RetornaSaldoConta(agencia->contas[i]) > RetornaSaldoConta(M1)){
            M1 = agencia->contas[i];
        }
    }
    if(M1 == M2) M2 = agencia->contas[1];
    for(i = 0; i < agencia->qtdC; i++){
        if(RetornaSaldoConta(agencia->contas[i]) < RetornaSaldoConta(M1) &&
            RetornaSaldoConta(agencia->contas[i]) > RetornaSaldoConta(M2)){
            M2 = agencia->contas[i];
        }
    }

    printf("\nOs dois correntistas com maior saldo são:\nId: %d, Saldo: %.2f\nId: %d, Saldo: %.2f",
    RetornaIdConta(M1), RetornaSaldoConta(M1), RetornaIdConta(M2), RetornaSaldoConta(M2));
}

void ImprimeSaldoTotal(tAgencia* agencia){
    float soma = 0;
    int i;
    for(i = 0; i < agencia->qtdC; i++){
        soma += RetornaSaldoConta(agencia->contas[i]);
    }
    printf("\nO saldo total da agencia eh: %.2f", soma);
}