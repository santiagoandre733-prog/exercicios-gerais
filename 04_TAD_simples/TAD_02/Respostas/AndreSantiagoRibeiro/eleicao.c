#include "eleicao.h"

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

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    int i;
    scanf("%d ", &eleicao.totalEleitores);

    for(i = 0; i < eleicao.totalEleitores; i++){
        eleicao.eleitores[i] = LeEleitor();
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
                    IncrementaVotoCandidato(eleicao.governadores[j]);
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
                    IncrementaVotoCandidato(eleicao.presidentes[j]);
                    verif = 1;
                }
            }
            if(!verif){
                eleicao.votosNulosPresidente++;
            }
        }
    }

    
}