#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filme.h"

tFilme* CriarFilme(){
    tFilme *filme = (tFilme*) malloc(sizeof(tFilme));
    filme->qtdAlugada = 0;

    return filme;
}

void LeFilme(tFilme *filme, int codigo){
    scanf("%[^,],%d,%d ", filme->nome, &filme->valor, &filme->qtdEstoque);
    filme->codigo = codigo;
    //2,Shrek,4,1
}

void DestruirFilme (tFilme* filme){
    free(filme);
}

int ObterCodigoFilme (tFilme* filme){
    return filme->codigo;
}

void ImprimirNomeFilme (tFilme* filme){
    printf("%s", filme->nome);
}

int ObterValorFilme (tFilme* filme){
    return filme->valor;
}

int ObterQtdEstoqueFilme (tFilme* filme){
    return filme->qtdEstoque;
}

int ObterQtdAlugadaFilme (tFilme* filme){
    return filme->qtdAlugada;
}

int EhMesmoCodigoFilme (tFilme* filme, int codigo){
    return filme->codigo == codigo;
}

void AlugarFilme (tFilme* filme){
    filme->qtdAlugada += 1;
    filme->qtdEstoque -= 1;
}

void DevolverFilme (tFilme* filme){
    filme->qtdAlugada -= 1;
    filme->qtdEstoque += 1;
}

int CompararNomesFilmes (tFilme* filme1, tFilme* filme2){
    return strcmp(filme1->nome, filme2->nome);
}