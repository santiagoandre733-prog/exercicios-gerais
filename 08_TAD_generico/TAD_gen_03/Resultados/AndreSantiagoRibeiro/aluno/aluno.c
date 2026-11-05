#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define TAM_MAX_STRING 50

struct Aluno {
    char nome[TAM_MAX_STRING];
    char genero;
    float nota;
};

tAluno *CriaAluno(){
    tAluno *a = (tAluno*) malloc(sizeof(tAluno));
    return a;
}

void DestroiAluno(data_type aluno){
    free((tAluno*)aluno);
}

void LeAluno(tAluno *aluno){
    scanf("%[^;];%c;%f ", aluno->nome, &aluno->genero, &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno){
    return aluno->genero;
}

float GetNotaAluno(tAluno *aluno){
    return aluno->nota;
}