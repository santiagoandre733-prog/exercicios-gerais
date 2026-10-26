#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"
#include "defesa.h"
#include "missil.h"

struct cidade {
    char nome[MAX_NOME];
    tDefesa defesa[QTD_DEF];
    tMissil missil[QTD_MIS];
    int qtdD;
    int qtdM;
    float x;
    float y;
    float totalDanoM;
};

tCidade CriaCidade(){
    tCidade cidade = (tCidade) malloc(sizeof(struct cidade));
    cidade->qtdD = 0;
    cidade->qtdM = 0;
    cidade->totalDanoM = 0;
}

tCidade LeEntrada(tCidade cidade){
    scanf("%s %f %f ", cidade->nome, &cidade->x, &cidade->y);
    char c;
    while(1){
        scanf("%c", &c);
        if(c == DEFESA){
            cidade->defesa[cidade->qtdD] = LeDefesa();
            cidade->qtdD += 1;
        }
        else if(c == MISSIL){
            cidade->missil[cidade->qtdM] = LeMissil();
            cidade->qtdM += 1;
        }
        else if(c == ENCERRAR) break;
    }

    return cidade;
}

void ImprimeCidade(tCidade cidade){
    int i;
    for(i = 0; i < cidade->qtdD; i++){
        ImprimeDefesa(cidade->defesa[i]);
    }
    for(i = 0; i < cidade->qtdM; i++){
        ImprimeMissil(cidade->missil[i]);
    }
}

void LiberaCidade(tCidade cidade){
    int i;
    for(i = 0; i < cidade->qtdD; i++){
        LiberaDefesa(cidade->defesa[i]);
    }
    for(i = 0; i < cidade->qtdM; i++){
        LiberaMissil(cidade->missil[i]);
    }
    free(cidade);
}

void ProcessaAtaques(tCidade cidade){
    int i, j;
    for(i = 0; i < cidade->qtdM; i++){
        cidade->totalDanoM += GetMissilPoder(cidade->missil[i]);//somatorio de dano original dos misseis
        if((GetMissilX(cidade->missil[i]) <= cidade->x) && (GetMissilY(cidade->missil[i]) <= cidade->y)){//dentro da cidade

            for(j = 0; j < cidade->qtdD; j++){
                if(VerificaSeDentroArea(cidade->defesa[j], GetMissilX(cidade->missil[i]), GetMissilY(cidade->missil[i]))
                    && PodeDefender(cidade->defesa[j])){
                        ReduzPoder(cidade->missil[i], GetDefesaPoder(cidade->defesa[j]));
                        UsaDefesa(cidade->defesa[j]);
                }
            }
        }
    }
}

void ImprimeDados(tCidade cidade){
    float danoDado = 0;
    int i;
    for(i = 0; i < cidade->qtdM; i++){
        danoDado += GetMissilPoder(cidade->missil[i]);
    }

    float efetividade = ((cidade->totalDanoM - danoDado) / cidade->totalDanoM) * 100;
    ImprimeCidade(cidade);
    printf("Efetividade: %.2f%%\n", efetividade);
}