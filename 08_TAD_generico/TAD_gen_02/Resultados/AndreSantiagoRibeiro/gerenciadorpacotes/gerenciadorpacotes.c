#include <stdio.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"

struct gerenciadorpacotes {
    tPacote **pacotes;
    int qtd;
};

tGerenciador* CriaGerenciador(){
    tGerenciador *g = (tGerenciador*) calloc(1, sizeof(tGerenciador));
    return g;
}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    geren->pacotes = realloc(geren->pacotes, (geren->qtd + 1)*sizeof(tPacote*));
    geren->pacotes[geren->qtd] = pac;
    geren->qtd += 1;
}

void DestroiGerenciador(tGerenciador* geren){
    int i;
    for(i = 0; i < geren->qtd; i++){
        DestroiPacote(geren->pacotes[i]);
    }
    free(geren->pacotes);
    free(geren);
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->pacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador* geren){
    int i;
    for(i = 0; i < geren->qtd; i++){
        ImprimePacote(geren->pacotes[i]);
    }
}