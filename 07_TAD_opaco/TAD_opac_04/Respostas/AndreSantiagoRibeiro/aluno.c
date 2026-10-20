#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_STRING_PADRAO 50

struct Aluno {
    char *nome;
    int matricula;
    int n1, n2, n3;
};

tAluno* CriaAluno(){
    tAluno *aluno = (tAluno*) malloc(sizeof(tAluno));
    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno){
    aluno->nome = (char*) malloc(TAM_STRING_PADRAO * sizeof(char));
    scanf("%[^\n]\n", aluno->nome);
    scanf("%d ", &aluno->matricula);
    scanf("%d %d %d ", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula > aluno2->matricula){
        return 1;
    }
    else if(aluno1->matricula < aluno2->matricula){
        return -1;
    }
    else {
        return 0;
    }
}

int CalculaMediaAluno(tAluno* aluno){
    return (aluno->n1 + aluno->n2 + aluno->n3)/3;
}

int VerificaAprovacao(tAluno* aluno){
    return CalculaMediaAluno(aluno) >= 7;
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}