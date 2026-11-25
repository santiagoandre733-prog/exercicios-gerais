#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define TAM_STRING 51

struct Aluno {
    char nome[TAM_STRING];
    char dataNascimento[TAM_STRING];
    char curso[TAM_STRING];
    float prctConclusao;
    float cfRendimento;
};

tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento){
    tAluno *a = malloc(sizeof(tAluno));
    strcpy(a->nome, nome);
    strcpy(a->dataNascimento, dataNascimento);
    strcpy(a->curso, curso);
    a->prctConclusao = prctConclusao;
    a->cfRendimento = cfRendimento;

    return a;
}

void DestroiAluno(tAluno *aluno){
    free(aluno);
}
