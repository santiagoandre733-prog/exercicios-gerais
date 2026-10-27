#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct Conta {
    int id;
    float saldo;
};

tConta* CriaConta(int id){
    tConta *conta = (tConta*) malloc(sizeof(tConta));
    conta->saldo = 0;
    conta->id = id;

    return conta;
}

void DestroiConta(tConta* conta){
    free(conta);
}

void AlteraSaldoConta(tConta* conta, float valor){
    conta->saldo += valor;
}

int ConfereIdConta(tConta* conta, int id){
    return conta->id == id;
}

int RetornaIdConta(tConta* conta){
    return conta->id;
}

float RetornaSaldoConta(tConta* conta){
    return conta->saldo;
}