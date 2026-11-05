#include <stdio.h>
#include "gerenciadorpacotes.h"

int main(){
    tGerenciador *g = CriaGerenciador();
    int n;
    printf("\n");
    while(1){
        printf("Escolha uma opcao:\n\t(1) Cadastrar um novo pacote\n\t(2) Imprimir um pacote especifico\n\t(3) Imprimir todos os pacotes e sair\n");
        scanf("%d ", &n);
        if(n == 1){
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");
            int tipo, tam;
            scanf("%d %d ", &tipo, &tam);
            if(tipo == INT || tipo == CHAR){
                tPacote *p = CriaPacote(tipo, tam);
                LePacote(p);
                AdicionaPacoteNoGerenciador(g, p);
            }
            else {
                printf("Digite um tipo valido!\n");
            }
        }
        else if(n == 2){

        }
        else if(n == 3){
            ImprimirTodosPacotes(g);
            break;
        }
        else {
            printf("Escolha uma opcao valida para o menu!\n");
        }
    }
    DestroiGerenciador(g);

    return 0;
}