#include "tabuleiro.h"

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;
    tabuleiro.peca1 = 'x';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for( j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(peca == PECA_1){
        tabuleiro.posicoes[x][y] = tabuleiro.peca1;
    }
    else if(peca == PECA_2){
        tabuleiro.posicoes[x][y] = tabuleiro.peca2;
    }

    return tabuleiro;
}