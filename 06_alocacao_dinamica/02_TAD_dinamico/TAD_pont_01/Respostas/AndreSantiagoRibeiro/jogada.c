#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

tJogada* CriaJogada(){
    tJogada *jogada = (tJogada*) malloc(sizeof(tJogada));
    return jogada;
}

void DestroiJogada(tJogada* jogada){
    free(jogada);
}

void LeJogada(tJogada* jogada){
    printf("Digite uma posicao (x e y):\n");
    if(scanf("%d %d ", &jogada->x, &jogada->y) == 2) jogada->sucesso = 1;
    else jogada->sucesso = 0;
}

int ObtemJogadaX(tJogada* jogada){
    return jogada->x;
}

int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada* jogada){
    return jogada->sucesso;
}