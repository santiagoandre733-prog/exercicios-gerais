#include <stdio.h>
#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"

tJogo CriaJogo(){
    tJogo jogo;
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    jogo.tabuleiro = CriaTabuleiro();
    return jogo;
}

void ComecaJogo(tJogo jogo){
    int id;

    id = ID_JOGADOR_1;
    while(!AcabouJogo(jogo)){
        if(id == ID_JOGADOR_1){
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
            id = ID_JOGADOR_2;
        }
        else if(id == ID_JOGADOR_2){
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
            id = ID_JOGADOR_1;
        }
        ImprimeTabuleiro(jogo.tabuleiro);
    }
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
    do {
        scanf("%c", &c);
    } while(c != 's' && c != 'n');
    scanf("\n");
    if(c == 's'){
        return 1;
    }
    else if(c == 'n'){
        return 0;
    }
}