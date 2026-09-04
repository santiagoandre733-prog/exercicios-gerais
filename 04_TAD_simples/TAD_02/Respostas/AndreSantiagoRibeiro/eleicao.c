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
}