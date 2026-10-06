#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

tEleicao* InicializaEleicao(){
    tEleicao *eleicao = (tEleicao*) malloc(sizeof(tEleicao));
    eleicao->votosBrancosGovernador = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosGovernador = 0;
    eleicao->votosNulosPresidente = 0;


    //candidatos
    eleicao->totalPresidentes = 0;
    eleicao->totalGovernadores = 0;

    eleicao->governadores = NULL;
    eleicao->presidentes = NULL;

    int total;
    scanf("%d ", &total);
    int i;
    for(i = 0; i < total; i++){
        tCandidato *candidato = CriaCandidato();
        tCandidato **temp;
        LeCandidato(candidato);

        if(ObtemCargo(candidato) == 'P'){
            eleicao->totalPresidentes += 1;
            temp = (tCandidato**) realloc(eleicao->presidentes, eleicao->totalPresidentes*sizeof(tCandidato*));
            temp[eleicao->totalPresidentes - 1] = candidato;
            eleicao->presidentes = temp;
        }
        
        else if(ObtemCargo(candidato) == 'G'){
            eleicao->totalGovernadores += 1;
            temp = (tCandidato**) realloc(eleicao->governadores, eleicao->totalGovernadores*sizeof(tCandidato*));
            temp[eleicao->totalGovernadores - 1] = candidato;
            eleicao->governadores = temp;
        }
    }

    eleicao->eleitores = NULL;
    

    return eleicao;
}

void ApagaEleicao(tEleicao* eleicao){
    int i;
    for(i = 0; i < eleicao->totalGovernadores; i++){
        ApagaCandidato(eleicao->governadores[i]);
    }
    free(eleicao->governadores);

    for(i = 0; i < eleicao->totalPresidentes; i++){
        ApagaCandidato(eleicao->presidentes[i]);
    }
    free(eleicao->presidentes);

    for(i = 0; i < eleicao->totalEleitores; i++){
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->eleitores);
    free(eleicao);
}

void RealizaEleicao(tEleicao* eleicao){
    scanf("%d ", &eleicao->totalEleitores);
    eleicao->eleitores = (tEleitor**) malloc(eleicao->totalEleitores*sizeof(tEleitor*));
    int i;
    for(i = 0; i < eleicao->totalEleitores; i++){
        eleicao->eleitores[i] = CriaEleitor();
        LeEleitor(eleicao->eleitores[i]);
    }
}

void ImprimeResultadoEleicao(tEleicao* eleicao){
    int i, j;
    //checagem de anulacao
    for(i = 0; i < eleicao->totalEleitores; i++){
        for(j = i + 1; j < eleicao->totalEleitores; j++){
            if(EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j])){
                printf("ELEICAO ANULADA\n");
                return;
            }
        }
    }
    
    //contagem dos votos
    for(i = 0; i < eleicao->totalEleitores; i++){
        //Presidente
        if(ObtemVotoPresidente(eleicao->eleitores[i]) == 0){
            eleicao->votosBrancosPresidente += 1;
        }
        else {
            for(j = 0; j < eleicao->totalPresidentes; j++){
                if(VerificaIdCandidato(eleicao->presidentes[j], ObtemVotoPresidente(eleicao->eleitores[i]))){
                    IncrementaVotoCandidato(eleicao->presidentes[j]);
                    break;
                }
                if(j == eleicao->totalPresidentes - 1){
                    eleicao->votosNulosPresidente += 1;
                }
            }
        }

        //Governador
        if(ObtemVotoGovernador(eleicao->eleitores[i]) == 0){
            eleicao->votosBrancosGovernador += 1;
        }
        else {
            for(j = 0; j < eleicao->totalGovernadores; j++){
                if(VerificaIdCandidato(eleicao->governadores[j], ObtemVotoGovernador(eleicao->eleitores[i]))){
                    IncrementaVotoCandidato(eleicao->governadores[j]);
                    break;
                }
                if(j == eleicao->totalGovernadores - 1){
                    eleicao->votosNulosGovernador += 1;
                }
            }
        }
    }

    //escolhendo vencedores
    tCandidato presidente = *eleicao->presidentes[0];
    tCandidato governador = *eleicao->governadores[0];

    int empateP = 0;
    int empateG = 0;

    for(i = 1; i < eleicao->totalPresidentes; i++){
        if(ObtemVotos(eleicao->presidentes[i]) > ObtemVotos(&presidente)){
            presidente = *eleicao->presidentes[i];
            empateP = 0;
        }
        else if(ObtemVotos(eleicao->presidentes[i]) == ObtemVotos(&presidente)){
            empateP = 1;
        }
    }

    for(i = 1; i < eleicao->totalGovernadores; i++){
        if(ObtemVotos(eleicao->governadores[i]) > ObtemVotos(&governador)){
            governador = *eleicao->governadores[i];
            empateG = 0;
        }
        else if(ObtemVotos(eleicao->governadores[i]) == ObtemVotos(&governador)){
            empateG = 1;
        }
    }

    //impressao dos resultados
    printf("- PRESIDENTE ELEITO: ");
    if(empateP){
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if(ObtemVotos(&presidente) < eleicao->votosBrancosPresidente + eleicao->votosNulosPresidente){
        printf("SEM DECISAO\n");
    }
    else {
        ImprimeCandidato(&presidente, CalculaPercentualVotos(&presidente, eleicao->totalEleitores));
    }

    printf("- GOVERNADOR ELEITO: ");
    if(empateG){
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if(ObtemVotos(&governador) < eleicao->votosBrancosGovernador + eleicao->votosNulosGovernador){
        printf("SEM DECISAO\n");
    }
    else {
        ImprimeCandidato(&governador, CalculaPercentualVotos(&governador, eleicao->totalEleitores));
    }

    printf("- NULOS E BRANCOS: %d, %d\n", eleicao->votosNulosGovernador + eleicao->votosNulosPresidente,
                                        eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente);
}