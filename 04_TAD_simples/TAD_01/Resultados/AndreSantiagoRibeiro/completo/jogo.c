#include <stdio.h>
#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"

tJogo CriaJogo(){
    tJogo jogo;
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    jogo.tabuleiro = CriaTabuleiro();
}

void ComecaJogo(tJogo jogo){
    int id = ID_JOGADOR_1;
    //do {
        jogo = CriaJogo();
        while(!AcabouJogo(jogo)){
            if(id == ID_JOGADOR_1){
                jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
                id = ID_JOGADOR_2;
            }
            else if(id == ID_JOGADOR_2){
                jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
                id = ID_JOGADOR_1;
            }
        }
    //} while(ContinuaJogo());
}

int AcabouJogo(tJogo jogo){
    if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)){
        printf("JOGADOR 1 Venceu!\n");
        return 1;
    }
    if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
        printf("JOGADOR 2 Venceu!\n");
        return 1;
    }
    if(!TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        printf("Sem vencedor!\n");
        return 1;
    }
    return 0;
}

int ContinuaJogo(){
    char c;
    printf("Jogar novamente? (s,n)\n");
    scanf("%c ", &c);
    if(c == 's'){
        return 1;
    }
    else if(c == 'n'){
        return 0;
    }
}