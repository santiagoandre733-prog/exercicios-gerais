#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

tJogo* CriaJogo(){
    tJogo *jogo = (tJogo*) malloc(sizeof(tJogo));
    jogo->jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo->jogador2 = CriaJogador(ID_JOGADOR_2);

    return jogo;
}

void ComecaJogo(tJogo* jogo){
    jogo->tabuleiro = CriaTabuleiro();
    int n = ID_JOGADOR_1;
    while(!AcabouJogo(jogo)){
        if(n == ID_JOGADOR_1){
            JogaJogador(jogo->jogador1, jogo->tabuleiro);
            n = ID_JOGADOR_2;
        }
        else if(n == ID_JOGADOR_2){
            JogaJogador(jogo->jogador2, jogo->tabuleiro);
            n = ID_JOGADOR_1;
        }
        ImprimeTabuleiro(jogo->tabuleiro);
    }
    if(VenceuJogador(jogo->jogador1, jogo->tabuleiro)){
        printf("JOGADOR 1 Venceu!\n");
    }
    else if(VenceuJogador(jogo->jogador2, jogo->tabuleiro)){
        printf("JOGADOR 2 Venceu!\n");
    }
    else {
        printf("Sem vencedor!\n");
    }
    DestroiTabuleiro(jogo->tabuleiro);
}

int AcabouJogo(tJogo* jogo){
    if(!TemPosicaoLivreTabuleiro(jogo->tabuleiro) || VenceuJogador(jogo->jogador1, jogo->tabuleiro)
    || VenceuJogador(jogo->jogador2, jogo->tabuleiro)) return 1;
    return 0;
}

int ContinuaJogo(){
    char c;
    printf("Jogar novamente? (s,n)\n");
    while(1){
        scanf("%c", &c);
        if(c == 's') return 1;
        else if(c == 'n') return 0;
    }   
}

void DestroiJogo(tJogo* jogo){
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    free(jogo);
}