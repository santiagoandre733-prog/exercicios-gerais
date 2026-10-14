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
    free(locadora->filme);
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
    //if(!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))){
        locadora->numFilmes += 1;
        locadora->filme = (tFilme**) realloc(locadora->filme, locadora->numFilmes*sizeof(tFilme*));
        locadora->filme[locadora->numFilmes - 1] = filme;

        printf("Filme cadastrado %d - ", ObterCodigoFilme(filme));
        ImprimirNomeFilme(filme);
        printf("\n");
        //Filme cadastrado 1 - A Sociedade Do Anel
    //}
}

void LerCadastroLocadora (tLocadora* Locadora){
    int codigo;
    while(scanf("%d,", &codigo) == 1){
        tFilme *filme = CriarFilme();
        LeFilme(filme, codigo);
        if(!VerificarFilmeCadastrado(Locadora, codigo)){
            CadastrarFilmeLocadora(Locadora, filme);
        }
        else {
            DestruirFilme(filme);
        }
    }
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    int custo = 0, qtd = 0;
    for(i = 0; i < quantidadeCodigos; i++){
        int vef = 0;
        for(j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])){
                vef = 1;
                if(ObterQtdEstoqueFilme(locadora->filme[j])){
                    AlugarFilme(locadora->filme[j]);
                    custo += ObterValorFilme(locadora->filme[j]);
                    qtd++;
                }
                else {
                    printf("Filme %d - ", codigos[i]);
                    ImprimirNomeFilme(locadora->filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    //Filme 4 - Shrek nao disponivel no estoque. Volte mais tarde.
                }
            }
        }
        if(!vef){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
    if(qtd > 0) printf("Total de filmes alugados: %d com custo de R$%d\n", qtd, custo);
    //Total de filmes alugados: 1 com custo de R$5
}

void LerAluguelLocadora (tLocadora* locadora){
    int quantidadeCodigos = 0;
    int *codigos = NULL;
    int codigo;
    while(scanf("%d ", &codigo) == 1){
        quantidadeCodigos++;
        codigos = (int*) realloc(codigos, quantidadeCodigos*sizeof(int));
        codigos[quantidadeCodigos - 1] = codigo;
    }
    //scanf("# ");
    AlugarFilmesLocadora(locadora, codigos, quantidadeCodigos);
    free(codigos);
}

void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int i, j;
    for(i = 0; i < quantidadeCodigos; i++){
        for(j = 0; j < locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i])){
                DevolverFilme(locadora->filme[j]);
                locadora->lucro += ObterValorFilme(locadora->filme[j]);
                printf("Filme %d - ", ObterCodigoFilme(locadora->filme[j]));
                ImprimirNomeFilme(locadora->filme[j]);
                printf(" Devolvido!\n");
                //Filme 1 - A Sociedade Do Anel Devolvido!
            }
        }
    }
}

void LerDevolucaoLocadora (tLocadora* locadora){
    int quantidadeCodigos = 0;
    int *codigos = NULL;
    int codigo;
    while(scanf("%d ", &codigo) == 1){
        quantidadeCodigos++;
        codigos = (int*) realloc(codigos, quantidadeCodigos*sizeof(int));
        codigos[quantidadeCodigos - 1] = codigo;
    }
    //scanf("# ");
    DevolverFilmesLocadora(locadora, codigos, quantidadeCodigos);
    free(codigos);
}

void OrdenarFilmesLocadora (tLocadora* locadora){
    int i, j;
    tFilme *temp;
    for(i = 0; i < locadora->numFilmes - 1; i++){
        for(j = i + 1; j < locadora->numFilmes; j++){
            if(CompararNomesFilmes(locadora->filme[j], locadora->filme[i]) == -1){
                temp = locadora->filme[i];
                locadora->filme[i] = locadora->filme[j];
                locadora->filme[j] = temp;
            }
        }
    }
}

void ConsultarEstoqueLocadora (tLocadora* locadora){
    printf("~ESTOQUE~\n");
    int i;
    for(i = 0; i < locadora->numFilmes; i++){
        printf("%d - ", ObterCodigoFilme(locadora->filme[i]));
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
    }
    //~ESTOQUE~
    //1 - A Sociedade Do Anel Fitas em estoque: 0
}

void ConsultarLucroLocadora (tLocadora* locadora){
    if(locadora->lucro > 0) printf("\nLucro total R$%d\n", locadora->lucro);
    //Lucro total R$5
}