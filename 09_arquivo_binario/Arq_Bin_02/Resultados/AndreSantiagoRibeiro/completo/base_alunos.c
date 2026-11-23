#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_alunos.h"
#include "aluno.h"

struct BaseAlunos {
    tAluno **alunos;
    int qtdAlunos;
};

tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos *b = calloc(1, sizeof(tBaseAlunos));
    return b;
}

void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    int i;
    for(i = 0; i < baseAlunos->qtdAlunos; i++){
        DestruirAluno(baseAlunos->alunos[i]);
    }
    free(baseAlunos->alunos);
    free(baseAlunos);
}

void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    FILE *f = fopen(nomeArquivo, "rb");
    fread(&baseAlunos->qtdAlunos, sizeof(int), 1, f);
    //printf("%d\n\n\n", baseAlunos->qtdAlunos);
    baseAlunos->alunos = malloc((baseAlunos->qtdAlunos)*sizeof(tAluno*));
    int i;
    for(i = 0; i < baseAlunos->qtdAlunos; i++){
        tAluno *a = LeAluno(f);
        baseAlunos->alunos[i] = a;
    }
    fclose(f);
}

float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float soma = 0;
    int i;
    for(i = 0; i < baseAlunos->qtdAlunos; i++){
        soma += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return soma/baseAlunos->qtdAlunos;
}