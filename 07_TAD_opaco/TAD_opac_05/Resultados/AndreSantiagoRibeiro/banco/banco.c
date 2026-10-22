#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include "conta.h"

#define MAX_CONTAS 5

struct Banco {
    tConta **contas;
    int numContas;
};

tBanco *CriaBanco(){
    tBanco *banco = (tBanco*) malloc(sizeof(tBanco));
    int i;
    banco->contas = (tConta**) malloc(MAX_CONTAS * sizeof(tConta*));
    //for(i = 0; i < MAX_CONTAS; i++){
    //    banco->contas[i] = CriaConta();
    //}

    banco->numContas = 0;
}

void DestroiBanco(tBanco *banco){
    int i;
    for(i = 0; i < banco->numContas; i++){
        DestroiConta(banco->contas[i]);
    }
    free(banco->contas);
    free(banco);
}

void AbreContaBanco(tBanco *banco){
    banco->contas[banco->numContas] = CriaConta();
    LeConta(banco->contas[banco->numContas]);
    banco->numContas += 1;
}

void SaqueContaBanco(tBanco *banco){
    int numero;
    float valor;
    scanf("%d %f ", &numero, &valor);
    int i;
    for(i = 0; i < banco->numContas; i++){
        if(VerificaConta(banco->contas[i], numero)){
            SaqueConta(banco->contas[i], valor);
        }
    }
}

void DepositoContaBanco(tBanco *banco){
    int numero;
    float valor;
    scanf("%d %f ", &numero, &valor);
    int i;
    for(i = 0; i < banco->numContas; i++){
        if(VerificaConta(banco->contas[i], numero)){
            DepositoConta(banco->contas[i], valor);
        }
    }
}

void TransferenciaContaBanco(tBanco *banco){
    int numeroO, numeroD;
    float valor;
    scanf("%d %d %f ", &numeroD, &numeroO, &valor);
    int i;
    tConta *contaO;
    tConta *contaD;
    for(i = 0; i < banco->numContas; i++){
        if(VerificaConta(banco->contas[i], numeroO)){
            contaO = banco->contas[i];
        }
        else if(VerificaConta(banco->contas[i], numeroD)){
            contaD = banco->contas[i];
        }
    }
    TransferenciaConta(contaD, contaO, valor);
}

void ImprimeRelatorioBanco(tBanco *banco){
    printf("===| Imprimindo Relatorio |===\n");
    int i;
    for(i = 0; i < banco->numContas; i++){
        ImprimeConta(banco->contas[i]);
    }
}