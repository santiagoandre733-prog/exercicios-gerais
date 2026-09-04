#include "eleicao.h"
#include <stdio.h>

tEleicao InicializaEleicao(){
    tEleicao eleicao;
    int qtd, i;
    scanf("%d ", &qtd);

    tCandidato candidatos[qtd];
    for(i = 0; i < qtd; i++){
        candidatos[i] = LeCandidato();
    }

    eleicao.totalGovernadores = 0;
    eleicao.totalPresidentes = 0;
    for(i = 0; i < qtd; i++){
        if(ObtemCargo(candidatos[i]) == 'P'){
            eleicao.presidentes[eleicao.totalPresidentes] = candidatos[i];
            eleicao.totalPresidentes++;
        }
        else if(ObtemCargo(candidatos[i]) == 'G'){
            eleicao.governadores[eleicao.totalGovernadores] = candidatos[i];
            eleicao.totalGovernadores++;
        }
    }

    if(eleicao.totalPresidentes > 3 || eleicao.totalGovernadores > 3){
        printf("ELEICAO ANULADA\n");
        exit(1);
    }

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    int i, j;
    scanf("%d ", &eleicao.totalEleitores);
    if(eleicao.totalEleitores > 10){
        printf("ELEICAO ANULADA\n");
        exit(1);
    }


    for(i = 0; i < eleicao.totalEleitores; i++){
        eleicao.eleitores[i] = LeEleitor();
    }

    //checagem de eleitor repetido
    for(i = 0; i < eleicao.totalEleitores; i++){
        for(j = i + 1; j < eleicao.totalEleitores; j++){
            if(EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])){
                printf("ELEICAO ANULADA\n");
                exit(1);
            }
        }
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao){
    int i, j;

    //contagem dos votos
    for(i = 0; i < eleicao.totalEleitores; i++){
        int verif = 0;
        if(ObtemVotoGovernador(eleicao.eleitores[i]) == 0){
            eleicao.votosBrancosGovernador++;
        }
        else {
            for(j = 0; j < eleicao.totalGovernadores; j++){
                if(VerificaIdCandidato(eleicao.governadores[j], ObtemVotoGovernador(eleicao.eleitores[i]))){
                    eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                    verif = 1;
                }
            }
            if(!verif){
                eleicao.votosNulosGovernador++;
            }
        }
        verif = 0;
        if(ObtemVotoPresidente(eleicao.eleitores[i]) == 0){
            eleicao.votosBrancosPresidente++;
        }
        else {
            for(j = 0; j < eleicao.totalPresidentes; j++){
                if(VerificaIdCandidato(eleicao.presidentes[j], ObtemVotoPresidente(eleicao.eleitores[i]))){
                    eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                    verif = 1;
                }
            }
            if(!verif){
                eleicao.votosNulosPresidente++;
            }
        }
    }

    //apuracao presidente
    int empateP = 0;
    tCandidato presidente;
    for(i = 0; i < eleicao.totalPresidentes; i++){
        if(i == 0){
            presidente = eleicao.presidentes[i];
        }
        else if(ObtemVotos(eleicao.presidentes[i]) > ObtemVotos(presidente)){
            presidente = eleicao.presidentes[i];
            empateP = 0;
        }
        else if(ObtemVotos(eleicao.presidentes[i]) == ObtemVotos(presidente)){
            empateP = 1;
        }
    }
    
    //apuracao governador
    int empateG = 0;
    tCandidato governador;
    for(i = 0; i < eleicao.totalGovernadores; i++){
        if(i == 0){
            governador = eleicao.governadores[i];
        }
        else if(ObtemVotos(eleicao.governadores[i]) > ObtemVotos(governador)){
            governador = eleicao.governadores[i];
            empateG = 0;
        }
        else if(ObtemVotos(eleicao.governadores[i]) == ObtemVotos(governador)){
            empateG = 1;
        }
    }

    //impressao
    float percentual;

    printf("- PRESIDENTE ELEITO: ");
    if(empateP){
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if(ObtemVotos(presidente) < (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)){
        printf("SEM DECISAO\n");
    }
    else {
        percentual = CalculaPercentualVotos(presidente, eleicao.totalEleitores);
        ImprimeCandidato(presidente, percentual);
    }

    printf("- GOVERNADOR ELEITO: ");
    if(empateG){
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if(ObtemVotos(governador) < (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)){
        printf("SEM DECISAO\n");
    }
    else {
        percentual = CalculaPercentualVotos(governador, eleicao.totalEleitores);
        ImprimeCandidato(governador, percentual);
    }

    printf("- NULOS E BRANCOS: %d, %d\n", eleicao.votosNulosPresidente + eleicao.votosNulosGovernador, eleicao.votosBrancosPresidente + eleicao.votosBrancosGovernador);
}