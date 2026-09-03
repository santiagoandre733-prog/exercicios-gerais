#include <stdio.h>
#include "jogada.h"
#include "jogador.h"
#include "tabuleiro.h"

tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    int x, y;

    while(1){
        printf("Jogador %d\n", jogador.id);
        jogada = LeJogada();
        if(!FoiJogadaBemSucedida(jogada)){
            exit(1);
        }
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        if(!EhPosicaoValidaTabuleiro(x, y)){
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
            continue;
        }
        if(!EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
            continue;
        }

        break;
    }
    
    if(jogador.id == ID_JOGADOR_1){
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, PECA_1, x, y);
    }
    else if(jogador.id == ID_JOGADOR_2){
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, PECA_2, x, y);
    }

    printf("Jogada [%d,%d]!\n", x, y);
    //ImprimeTabuleiro(tabuleiro);

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    char c;
    int count = 0;
    if(jogador.id == ID_JOGADOR_1){
        c = tabuleiro.peca1;
    }
    else if(jogador.id == ID_JOGADOR_2){
        c = tabuleiro.peca2;
    }

    int i, j;
    //checagem horizontal
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[i][j] == c){
                count++;
            }
        }
        if(count == 3){
            return 1;
        }
        else {
            count = 0;
        }
    }

    //checagem vertical
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[j][i] == c){
                count++;
            }
        }
        if(count == 3){
            return 1;
        }
        else {
            count = 0;
        }
    }

    //checagem diagonal 1
    for(i = 0; i < TAM_TABULEIRO; i++){
        if(tabuleiro.posicoes[i][i] == c){
            count++;
        }
    }
    if(count == 3){
        return 1;
    }
    else {
        count = 0;
    }

    //checagem diagonal 2
    for(i = 0; i < TAM_TABULEIRO; i++){
        if(tabuleiro.posicoes[i][TAM_TABULEIRO - 1 - i] == c){
            count++;
        }
    }
    if(count == 3){
        return 1;
    }

    return 0;
}
