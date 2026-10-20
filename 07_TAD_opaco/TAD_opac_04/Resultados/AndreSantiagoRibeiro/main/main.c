#include <stdio.h>
#include "aluno.h"

void OrdenaAlunosMatricula(tAluno **alunos, int n);

int main(){
    int n;
    scanf("%d ", &n);
    tAluno *alunos[n];
    int i;
    for(i = 0; i < n; i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    OrdenaAlunosMatricula(alunos, n);
    for(i = 0; i < n; i++){
        if(VerificaAprovacao(alunos[i])) ImprimeAluno(alunos[i]);
        ApagaAluno(alunos[i]);
    }

    return 0;
}

void OrdenaAlunosMatricula(tAluno **alunos, int n){
    int i, j;
    tAluno *temp;
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(ComparaMatricula(alunos[j], alunos[i]) == -1){
                temp = alunos[j];
                alunos[j] = alunos[i];
                alunos[i] = temp;
            }
        }
    }
}