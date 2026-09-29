#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

tTabuleiro* CriaTabuleiro(){
    tTabuleiro *tabuleiro = (tTabuleiro*) malloc(sizeof(tTabuleiro));
    tabuleiro->posicoes = (char**) malloc(TAM_TABULEIRO * sizeof(char*));
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        tabuleiro->posicoes[i] = (char*) malloc(TAM_TABULEIRO * sizeof(char));
    }
    tabuleiro->peca1 = 'X';
    tabuleiro->peca2 = '0';
    tabuleiro->pecaVazio = '-';
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro->posicoes[i][j] = tabuleiro->pecaVazio;
        }
    }
    return tabuleiro;
}

void DestroiTabuleiro(tTabuleiro* tabuleiro){
    int i;
    for(i = 0; i < TAM_TABULEIRO; i++){
        free(tabuleiro->posicoes[i]);
    }
    free(tabuleiro->posicoes);
    free(tabuleiro);
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    if(peca == PECA_1){
        tabuleiro->posicoes[y][x] = tabuleiro->peca1;
    }
    else if(peca == PECA_2){
        tabuleiro->posicoes[y][x] = tabuleiro->peca2;
    }
}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio){
                return 1;
            }
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    if(peca == PECA_1){
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca1){
            return 1;
        }
        else {
            return 0;
        }
    }
    else if(peca == PECA_2){
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca2){
            return 1;
        }
        else {
            return 0;
        }
    }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio) return 1;
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x > 2 || x < 0 || y > 2 || y < 0) return 0;
    return 1;
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    int i, j;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}