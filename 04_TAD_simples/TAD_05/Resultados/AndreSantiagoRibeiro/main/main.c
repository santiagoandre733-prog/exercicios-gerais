#include "conta.h"
#include <stdio.h>

int EncontraIndiceConta(tConta *contas, int qtdContas, int numero);

int main(){
    int qtdUser;
    scanf("%d ", &qtdUser);
    tConta contas[qtdUser];

    int n, iAtual = 0;
    while(1){
        scanf("%d ", &n);
        if(n == 0){
            break;
        }
        else if(n == 1){
            int numero;
            float valor;
            scanf("%d %f ", &numero, &valor);
            int indice = EncontraIndiceConta(contas, qtdUser, numero);
            contas[indice] = SaqueConta(contas[indice], valor);
        }
        else if(n == 2){
            int numero;
            float valor;
            scanf("%d %f ", &numero, &valor);
            int indice = EncontraIndiceConta(contas, qtdUser, numero);
            contas[indice] = DepositoConta(contas[indice], valor);
        }
        else if(n == 3){
            int numero;
            char nome[20];
            char cpf[20];
            scanf("%s %s %d ", nome, cpf, &numero);
            tUsuario user = CriaUsuario(nome, cpf);
            contas[iAtual] = CriaConta(numero, user);
            iAtual++;
        }
        else if(n == 4){
            int i;
            printf("===| Imprimindo Relatorio |===\n");
            for(i = 0; i < qtdUser; i++){
                ImprimeConta(contas[i]);
            }
        }
    }

    return 0;
}

int EncontraIndiceConta(tConta *contas, int qtdContas, int numero){
    int i;
    for(i = 0; i < qtdContas; i++){
        if(VerificaConta(contas[i], numero)){
            return i;
        }
    }

    return -1;
}