#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno {
    char nome[100];
    char dtNasc[11];
    char curso[50];
    float periodo;
    float coeficiente;
};

tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno *a = malloc(sizeof(tAluno));
    strcpy(a->nome, nome);
    strcpy(a->dtNasc, dataNascimento);
    strcpy(a->curso, curso);
    a->periodo = periodo;
    a->coeficiente = coeficienteRendimento;

    return a;
}

void DestruirAluno(tAluno* aluno){
    free(aluno);
}

tAluno *LeAluno(FILE *arquivo_binario){
    char nome[100];
    char dtNasc[11];
    char curso[50];
    float periodo;
    float coeficiente;

    fread(nome, sizeof(char), 100, arquivo_binario);
    fread(dtNasc, sizeof(char), 11, arquivo_binario);
    fread(curso, sizeof(char), 50, arquivo_binario);
    fread(&periodo, sizeof(float), 1, arquivo_binario);
    fread(&coeficiente, sizeof(float), 1, arquivo_binario);

    tAluno *a = CriarAluno(nome, dtNasc, curso, periodo, coeficiente);
    return a;
}

float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->coeficiente;
}