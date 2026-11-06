#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"

typedef void (*ptrFuncao)(void*);

struct agendatarefas {
    void **tarefas;
    ptrFuncao *funcoesExecuta;
    ptrFuncao *funcoesDestroi;
    int *prioridades;
    int qtd;
    int idxAtual;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas *agenda = (tAgendaTarefas*) calloc(1, sizeof(tAgendaTarefas));
    agenda->qtd = numElem;
    agenda->tarefas = malloc(numElem*sizeof(void*));
    agenda->funcoesExecuta = (ptrFuncao*) malloc(numElem*sizeof(ptrFuncao));
    agenda->funcoesDestroi = (ptrFuncao*) malloc(numElem*sizeof(ptrFuncao));
    agenda->prioridades = (int*) malloc(numElem*sizeof(int));

    agenda->idxAtual = 0;

    return agenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    int i;
    for(i = 0; i < tar->qtd; i++){
        tar->funcoesDestroi[i](tar->tarefas[i]);
    }
    free(tar->tarefas);
    free(tar->funcoesDestroi);
    free(tar->funcoesExecuta);
    free(tar->prioridades);
    free(tar);
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    tar->prioridades[tar->idxAtual] = prioridade;
    tar->tarefas[tar->idxAtual] = tarefa;
    tar->funcoesExecuta[tar->idxAtual] = executa;
    tar->funcoesDestroi[tar->idxAtual] = destroi;
    tar->idxAtual += 1;
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    OrdenaTarefas(tar);
    int i;
    for(i = 0; i < tar->qtd; i++){
        tar->funcoesExecuta[i](tar->tarefas[i]);
    }
}

void OrdenaTarefas(tAgendaTarefas* tar){
    void* tempTarefa;
    ptrFuncao tempFuncEx;
    ptrFuncao tempFuncDe;
    int tempPrio;
 
    int i, j;
    for(i = 0; i < tar->qtd - 1; i++){
        
        for(j = 0; j < tar->qtd - 1 - i; j++){
            if(tar->prioridades[j] < tar->prioridades[j + 1]){
                tempTarefa = tar->tarefas[j];
                tempFuncEx = tar->funcoesExecuta[j];
                tempFuncDe = tar->funcoesDestroi[j];
                tempPrio = tar->prioridades[j];

                tar->tarefas[j] = tar->tarefas[j + 1];
                tar->funcoesExecuta[j] = tar->funcoesExecuta[j + 1];
                tar->funcoesDestroi[j] = tar->funcoesDestroi[j + 1];
                tar->prioridades[j] = tar->prioridades[j + 1];

                tar->tarefas[j + 1] = tempTarefa;
                tar->funcoesExecuta[j + 1] = tempFuncEx;
                tar->funcoesDestroi[j + 1] = tempFuncDe;
                tar->prioridades[j + 1] = tempPrio;
            }
        }
    }
}
