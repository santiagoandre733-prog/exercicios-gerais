#include "locadora.h"
#include <stdio.h>
#include <string.h>

int main(){
    tLocadora locadora;
    locadora = criarLocadora();
    char acao[50];
    while(scanf("%s ", acao) == 1){
        if(strcmp(acao, "Cadastrar") == 0){
            locadora = lerCadastroLocadora(locadora);
            printf("\n");
        }
        else if(strcmp(acao, "Estoque") == 0){
            consultarEstoqueLocadora(locadora);
            printf("\n");
        }
        else if(strcmp(acao, "Alugar") == 0){
            locadora = lerAluguelLocadora(locadora);
            printf("\n");
        }
        else if(strcmp(acao, "Devolver") == 0){
            locadora = lerDevolucaoLocadora(locadora);
            printf("\n");
        }
        locadora = ordenarFilmesLocadora(locadora);
    }

    consultarLucroLocadora(locadora);
    return 0;
}