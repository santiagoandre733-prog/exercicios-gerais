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
        if(ehMesmoCodigoFilme(locadora.filme[i], codigo)){
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    if(!verificarFilmeCadastrado(locadora, obterCodigoFilme(filme))){
        locadora.filme[locadora.numFilmes] = filme;
        printf("Filme cadastrado %d - ", obterCodigoFilme(locadora.filme[locadora.numFilmes]));
        imprimirNomeFilme(locadora.filme[locadora.numFilmes]);
        printf("\n");
        locadora.numFilmes++;
    }
    else {
        printf("Filme ja cadastrado no estoque\n");
    }
    return locadora;
}

tLocadora lerCadastroLocadora (tLocadora locadora){
    tFilme filme;
    int codigo;
    while(scanf("%d,", &codigo) == 1){
        filme = leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, filme);
    }
    scanf("# ");
    return locadora;
}

tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i, j, soma = 0, total = 0, flag1 = 0, flag2 = 0;
    for(i = 0; i < quantidadeCodigos; i++){
        for(j = 0; j < locadora.numFilmes; j++){
            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){
                if(obterQtdEstoqueFilme(locadora.filme[j]) > 0){
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                    soma += obterValorFilme(locadora.filme[j]);
                    total++;
                    flag2 = 1;
                }
                else {
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }
                flag1 = 1;
            }
        }
        if(!flag1){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
        flag1 = 0;
    }
    if(flag2)
    printf("Total de filmes alugados: %d com custo de R$%d\n", total, soma);

    return locadora;
}

tLocadora lerAluguelLocadora (tLocadora locadora){
    int codigos[100];
    int i = 0, codigo;
    while(scanf("%d ", &codigo) == 1){
        codigos[i] = codigo;
        i++;
    }
    scanf("# ");

    locadora = alugarFilmesLocadora(locadora, codigos, i);
    return locadora;
}

tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i, j, flag = 0;
    for(i = 0; i < quantidadeCodigos; i++){
        for(j = 0; j < locadora.numFilmes; j++){
            if(ehMesmoCodigoFilme(locadora.filme[j], codigos[i])){
                if(obterQtdAlugadaFilme(locadora.filme[j]) > 0){
                    locadora.filme[j] = devolverFilme(locadora.filme[j]);
                    locadora.lucro += obterValorFilme(locadora.filme[j]);
                    
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" Devolvido!\n");
                }
                else {
                    printf("Nao e possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                }
                flag = 1;
            }
        }
        if(!flag){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
        flag = 0;
    }

    return locadora;
}

tLocadora lerDevolucaoLocadora (tLocadora locadora){
    int codigos[100];
    int i = 0, codigo;
    while(scanf("%d ", &codigo) == 1){
        codigos[i] = codigo;
        i++;
    }
    scanf("# ");

    locadora = devolverFilmesLocadora(locadora, codigos, i);
    return locadora;
}

tLocadora ordenarFilmesLocadora (tLocadora locadora){
    tFilme temp;
    int i, j;
    for(i = 0; i < locadora.numFilmes; i++){
        for(j = i + 1; j < locadora.numFilmes; j++){
            if(compararNomesFilmes(locadora.filme[j], locadora.filme[i]) < 0){
                temp = locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j] = temp;
            }
        }
    }

    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora){
    int i;
    printf("~ESTOQUE~\n");
    for(i = 0; i < locadora.numFilmes; i++){
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

void consultarLucroLocadora (tLocadora locadora){
    if(locadora.lucro > 0)
    printf("\nLucro total R$%d\n", locadora.lucro);
}