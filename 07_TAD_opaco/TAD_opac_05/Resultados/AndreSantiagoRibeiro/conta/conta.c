#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

struct Conta {
    tUsuario *user;
    int numero;
    float saldo;
};

tConta *CriaConta(){
    tConta *c = (tConta*) malloc(sizeof(tConta));
    c->user = CriaUsuario();

    return  c;
}

void DestroiConta(tConta *conta){
    DestroiUsuario(conta->user);
    free(conta);
}

void LeConta(tConta *conta){
    conta->saldo = 0;
    LeUsuario(conta->user);
    scanf("%d ", &conta->numero);
}

void ImprimeConta(tConta *conta){
    printf("Conta: %d\nSaldo: R$ %.2f\n", conta->numero, conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero){
    return conta->numero == numero;
}

void SaqueConta(tConta *conta, float valor){
    if(conta->saldo >= valor) conta->saldo -= valor;
}

void DepositoConta(tConta *conta, float valor){
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor){
    if(origem->saldo >= valor){
        destino->saldo += valor;
        origem->saldo -= valor;
    }
}