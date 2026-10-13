#include <stdio.h>
#include <stdlib.h>
#include "locadora.h"

tLocadora* CriarLocadora (){
    tLocadora *locadora = (tLocadora*) calloc(1, sizeof(tLocadora));
    locadora->filme = NULL;

    return locadora;
}

void DestruirLocadora (tLocadora* locadora){
    int i;
    for(i = 0; i < locadora->numFilmes; i++){
        DestruirFilme(locadora->filme[i]);
    }
    free(locadora);
}

int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    int i;
    for(i = 0; i < locadora->numFilmes; i++){
        if(ObterCodigoFilme(locadora->filme[i]) == codigo){
            return 1;
        }
    }
    return 0;
}

void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    if(!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))){
        locadora->filme[locadora->numFilmes] = filme;
        locadora->numFilmes += 1;
    }
}

void LerCadastroLocadora (tLocadora* Locadora){
    tFilme *filme = CriarFilme();
    int codigo;
    scanf("%d,", &codigo);
    LeFilme(filme, codigo);
    CadastrarFilmeLocadora(Locadora, filme);
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    for(i = 0; i < quantidadeCodigos; i++){
        for(j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])){
                AlugarFilme(locadora->filme[j]);
            }
        }
    }
}

void LerAluguelLocadora (tLocadora* locadora){
    int quantidadeCodigos;
}