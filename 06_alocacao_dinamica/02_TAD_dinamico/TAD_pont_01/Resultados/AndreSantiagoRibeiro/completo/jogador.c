#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"

tJogador* CriaJogador(int idJogador){
    tJogador *jogador = (tJogador*) malloc(sizeof(tJogador));
    jogador->id = idJogador;
    return jogador;
}

void DestroiJogador(tJogador* jogador){
    free(jogador);
}

void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    tJogada *jogada = CriaJogada();
    LeJogada(jogada);
    if(!EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))){
        DestroiJogada(jogada);
        return;
    }
    if(!EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))){
        DestroiJogada(jogada);
        return;
    }
    MarcaPosicaoTabuleiro(tabuleiro, jogador->id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    DestroiJogada(jogada);
}

int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    int i, j, count1 = 0, count2 = 0;

    //checagem horizontal e vertical
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            //horizontal
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador->id)){
                count1++;
            }
            //vertical
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador->id)){
                count2++;
            }
        }
        if(count1 == TAM_TABULEIRO || count2 == TAM_TABULEIRO){
            return 1;
        }
        count1 = 0;
        count2 = 0;
    }

    //checagem diagonal
    for(i = 0; i < TAM_TABULEIRO; i++){
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, jogador->id)){
            count1++;
        }
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, TAM_TABULEIRO - i - 1, jogador->id)){
            count2++;
        }
    }
    if(count1 == TAM_TABULEIRO || count2 == TAM_TABULEIRO){
        return 1;
    }
    return 0;
}