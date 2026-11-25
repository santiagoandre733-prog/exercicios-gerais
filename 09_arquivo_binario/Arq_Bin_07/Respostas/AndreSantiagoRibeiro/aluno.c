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
    tAluno *a = calloc(1, sizeof(tAluno));
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

tAluno *LeAluno(){
    char nome[TAM_STRING];
    char dataNascimento[TAM_STRING];
    char curso[TAM_STRING];
    float prctConclusao;
    float cfRendimento;
    scanf(" %[^\n]\n", nome);
    scanf("%[^\n]\n", dataNascimento);
    scanf("%[^\n]\n", curso);
    scanf("%f ", &prctConclusao);
    scanf("%f ", &cfRendimento);
    tAluno *a = CriaAluno(nome, dataNascimento, curso, prctConclusao, cfRendimento);

    return a;
}

int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2){
    return strcmp(aluno1->nome, aluno2->nome);
}

int SalvaAluno(tAluno *aluno, FILE *file){
    return fwrite(aluno, sizeof(tAluno), 1, file)*sizeof(tAluno);

    /*int somaBytes = 0;

    int tamString = strlen(aluno->nome);
    somaBytes += fwrite(&tamString, sizeof(int), 1, file)*sizeof(int);
    somaBytes += fwrite(aluno->nome, sizeof(char), tamString + 1, file)*sizeof(char);

    tamString = strlen(aluno->dataNascimento);
    somaBytes += fwrite(&tamString, sizeof(int), 1, file)*sizeof(int);
    somaBytes += fwrite(aluno->dataNascimento, sizeof(char), tamString + 1, file)*sizeof(char);

    tamString = strlen(aluno->curso);
    somaBytes += fwrite(&tamString, sizeof(int), 1, file)*sizeof(int);
    somaBytes += fwrite(aluno->curso, sizeof(char), tamString + 1, file)*sizeof(char);

    somaBytes += fwrite(&aluno->prctConclusao, sizeof(float), 1, file)*sizeof(float);
    somaBytes += fwrite(&aluno->cfRendimento, sizeof(float), 1, file)*sizeof(float);
    
    return somaBytes;*/
}

int CarregaAluno(tAluno *aluno, FILE *file){
    return fread(aluno, sizeof(tAluno), 1, file)*sizeof(tAluno);

    //aluno = malloc(sizeof(tAluno));

    /*int tamString;
    int somaBytes = 0;

    somaBytes += fread(&tamString, sizeof(int), 1, file)*sizeof(int);
    somaBytes += fread(aluno->nome, sizeof(char), tamString + 1, file)*sizeof(char);

    somaBytes += fread(&tamString, sizeof(int), 1, file)*sizeof(int);
    somaBytes += fread(aluno->dataNascimento, sizeof(char), tamString + 1, file)*sizeof(char);

    somaBytes += fread(&tamString, sizeof(int), 1, file)*sizeof(int);
    somaBytes += fread(aluno->curso, sizeof(char), tamString + 1, file)*sizeof(char);

    somaBytes += fread(&aluno->prctConclusao, sizeof(float), 1, file)*sizeof(float);
    somaBytes += fread(&aluno->cfRendimento, sizeof(float), 1, file)*sizeof(float);

    return somaBytes;*/
}

void ImprimeNomeAluno(tAluno *aluno){
    printf("%s\n", aluno->nome);
}