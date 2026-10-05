#include <stdio.h>
#include <stdlib.h>
#include "candidato.h"

#define TAM_STRING 50

tCandidato* CriaCandidato(){
    tCandidato *candidato = (tCandidato*) malloc(sizeof(tCandidato));
    candidato->nome = (char*) calloc(TAM_STRING, sizeof(char));
    candidato->partido = (char*) calloc(TAM_STRING, sizeof(char));
    candidato->cargo = -1;
    candidato->id = -1;
    candidato->votos = -1;

    return candidato;
}

void ApagaCandidato(tCandidato* candidato){
    free(candidato->nome);
    free(candidato->partido);
    free(candidato);
}

void LeCandidato(tCandidato *candidato){
    scanf(" %[^,], %[^,], %c, %d ", candidato->nome, candidato->partido, &candidato->cargo, &candidato->id);
    candidato->votos = 0;
}

int VerificaIdCandidato(tCandidato *candidato, int id){
    return candidato->id == id;
}

int EhMesmoCandidato(tCandidato *candidato1, tCandidato *candidato2){
    return candidato1->id == candidato2->id;
}

char ObtemCargo(tCandidato* candidato){
    return candidato->cargo;
}

void IncrementaVotoCandidato(tCandidato* candidato){
    candidato->votos += 1;
}

int ObtemVotos(tCandidato* candidato){
    return candidato->votos;
}

float CalculaPercentualVotos(tCandidato* candidato, int totalVotos){
    return ((float)candidato->votos/totalVotos)*100;
}

void ImprimeCandidato (tCandidato* candidato, float percentualVotos){
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato->nome, candidato->partido, candidato->votos, percentualVotos);
}

//Edsger Dijkstra (Partido do Melhor Caminho (PMC)), 3 voto(s), 100.00%