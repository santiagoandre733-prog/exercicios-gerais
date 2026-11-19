#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define TAM_STRING 51

struct aluno {
    char nome[TAM_STRING];
    char dtNasc[TAM_STRING];
    char cursoUfes[TAM_STRING];
    char periodoIngresso[TAM_STRING];
    int percConclusao;
    float CRA;
};

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno** alunos = malloc(numeroAlunos*sizeof(Aluno*));
    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno *a = malloc(sizeof(Aluno));
    strcpy(a->nome, nome);
    strcpy(a->dtNasc, dtNasc);
    strcpy(a->cursoUfes, cursoUfes);
    strcpy(a->periodoIngresso, periodoIngresso);
    a->percConclusao = percConclusao;
    a->CRA = CRA;

    return a;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char nome[TAM_STRING];
    char dtNasc[TAM_STRING];
    char cursoUfes[TAM_STRING];
    char periodoIngresso[TAM_STRING];
    int percConclusao;
    float CRA;
    int i;
    for(i = 0; i < numeroAlunos; i++){
        scanf(" %[^\n]\n", nome);
        scanf("%[^\n]\n", dtNasc);
        scanf("%[^\n]\n", cursoUfes);
        scanf("%[^\n]\n", periodoIngresso);
        scanf("%d ", &percConclusao);
        scanf("%f ", &CRA);
        vetorAlunos[i] = CriaAluno(nome, dtNasc, cursoUfes, periodoIngresso, percConclusao, CRA);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    int i;
    for(i = 0; i < numeroAlunos; i++){
        free(alunos[i]);
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    FILE *f = fopen(fileName, "wb");
    int numBytes = 0;
    int i;
    numBytes += fwrite(&numeroAlunos, sizeof(numeroAlunos), 1, f);
    numBytes += fwrite(alunos, sizeof(*alunos), numeroAlunos, f);
    for(i = 0; i < numeroAlunos; i++){
        //numBytes += fwrite(alunos[i], sizeof(alunos[i]), 1, f);
        int tamanhoString = strlen(alunos[i]->nome) + 1;
        numBytes += fwrite(&tamanhoString, sizeof(int), 1, f);
        numBytes += fwrite(alunos[i]->nome, sizeof(char), tamanhoString, f);
        tamanhoString = strlen(alunos[i]->dtNasc) + 1;
        numBytes += fwrite(&tamanhoString, sizeof(int), 1, f);
        numBytes += fwrite(alunos[i]->dtNasc, sizeof(char), tamanhoString, f);
        tamanhoString = strlen(alunos[i]->cursoUfes) + 1;
        numBytes += fwrite(&tamanhoString, sizeof(int), 1, f);
        numBytes += fwrite(alunos[i]->cursoUfes, sizeof(char), tamanhoString, f);
        tamanhoString = strlen(alunos[i]->periodoIngresso) + 1;
        numBytes += fwrite(&tamanhoString, sizeof(int), 1, f);
        numBytes += fwrite(alunos[i]->periodoIngresso, sizeof(char), tamanhoString, f);
        numBytes += fwrite(&alunos[i]->percConclusao, sizeof(int), 1, f);
        numBytes += fwrite(&alunos[i]->CRA, sizeof(float), 1, f);
    }
    printf("Numero de bytes salvos: %d\n", numBytes);
    fclose(f);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    FILE *f = fopen(fileName, "rb");
    int numeroAlunos;
    fread(&numeroAlunos, sizeof(int), 1, f);
    fread(alunos, sizeof(Aluno*), numeroAlunos, f);
    //alunos = CriaVetorAlunos(numeroAlunos);
    char nome[TAM_STRING];
    char dtNasc[TAM_STRING];
    char cursoUfes[TAM_STRING];
    char periodoIngresso[TAM_STRING];
    int percConclusao;
    float CRA;
    int i;
    for(i = 0; i < numeroAlunos; i++){
        int tamanhoString;
        fread(&tamanhoString, sizeof(int), 1, f);
        fread(nome, sizeof(char), tamanhoString, f);
        fread(&tamanhoString, sizeof(int), 1, f);
        fread(dtNasc, sizeof(char), tamanhoString, f);
        fread(&tamanhoString, sizeof(int), 1, f);
        fread(cursoUfes, sizeof(char), tamanhoString, f);
        fread(&tamanhoString, sizeof(int), 1, f);
        fread(periodoIngresso, sizeof(char), tamanhoString, f);
        fread(&percConclusao, sizeof(int), 1, f);
        fread(&CRA, sizeof(float), 1, f);
        alunos[i] = CriaAluno(nome, dtNasc, cursoUfes, periodoIngresso, percConclusao, CRA);
    }
    fclose(f);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    int i;
    for(i = 0; i < numeroAlunos; i++){
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dtNasc);
        printf("Curso: %s\n", alunos[i]->cursoUfes);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodoIngresso);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->percConclusao);
        printf("CRA: %.2f\n", alunos[i]->CRA);
    }
}