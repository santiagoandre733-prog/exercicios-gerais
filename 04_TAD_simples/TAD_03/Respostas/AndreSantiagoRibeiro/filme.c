#include "filme.h"
#include <stdio.h>
#include <string.h>

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade){
    tFilme filme;
    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;

    return filme;
}

tFilme leFilme(int codigo){
    char nome[50];
    int valor, quantidade;

    scanf("%[^,],%d,%d ", &nome, &valor, &quantidade);

    tFilme filme = criarFilme(nome, codigo, valor, quantidade);
    return filme;
}

int obterCodigoFilme (tFilme filme){
    return filme.codigo;
}

void imprimirNomeFilme (tFilme filme){
    printf("%s", filme.nome);
}

int obterValorFilme (tFilme filme){
    return filme.valor;
}

int obterQtdEstoqueFilme (tFilme filme){
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme (tFilme filme){
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme (tFilme filme, int codigo){
    return filme.codigo == codigo;
}

tFilme alugarFilme (tFilme filme){
    filme.qtdEstoque--;
    filme.qtdAlugada++;
    return filme;
}

tFilme devolverFilme (tFilme filme){
    filme.qtdEstoque++;
    filme.qtdAlugada--;
    return filme;
}

int compararNomesFilmes (tFilme filme1, tFilme filme2){
    return strcmp(filme1.nome, filme2.nome);
}