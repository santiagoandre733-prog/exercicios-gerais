#include <stdio.h>
#include "locadora.h"
#include <string.h>

#define TAM_STRING 10

int main(){
    tLocadora *locadora = CriarLocadora();
    char c;
    char s[TAM_STRING];
    do {
        scanf("%s", s);

        if(strcmp(s, "Cadastrar") == 0){
            LerCadastroLocadora(locadora);
        }
        else if(strcmp(s, "Alugar") == 0){
            LerAluguelLocadora(locadora);
        }
        else if(strcmp(s, "Devolver") == 0){
            LerDevolucaoLocadora(locadora);
        }
        else if(strcmp(s, "Estoque") == 0){
            printf("\n");
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
        }

    } while(scanf("%c\n", &c) == 1);
    ConsultarLucroLocadora(locadora);
    DestruirLocadora(locadora);

    return 0;
}