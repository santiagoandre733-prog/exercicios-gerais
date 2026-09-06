#include "locadora.h"
#include <stdio.h>

tLocadora criarLocadora (){
    tLocadora locadora;
    locadora.lucro = 0;
    locadora.numFilmes = 0;

    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    int i;
    for(i = 0; i < locadora.numFilmes; i++){
        if(EhMesmoCodigoFilme(locadora.filme[i], codigo)){
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    if(!verificarFilmeCadastrado(locadora, obterCodigoFilme(filme))){
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes++;
    }
    else {
        printf("Filme ja cadastrado no estoque\n");
    }
    return locadora;
}