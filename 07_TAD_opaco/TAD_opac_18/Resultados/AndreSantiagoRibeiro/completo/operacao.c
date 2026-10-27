#include <stdio.h>
#include <stdlib.h>
#include "operacao.h"

struct Operacao {
    tConta *conta;
    float valor;
};

tOperacao* CriaOperacao(tConta* conta, float valor){
    tOperacao *op = (tOperacao*) malloc(sizeof(tOperacao));
    op->conta = conta;
    op->valor = valor;
    return op;
}

void DestroiOperacao(tOperacao* op){
    DestroiConta(op->conta);
    free(op);
}

float ConsultaValorOperacao(tOperacao* op){
    return op->valor;
}

void ImprimeOperacao(tOperacao* op){
    printf("\nOperação na conta %d com valor %.2f", RetornaIdConta(op->conta), op->valor);
}