#include "aluno.h"
#include <stdio.h>

int main(){
    int qtd;
    scanf("%d ", &qtd);
    tAluno alunos[qtd];
    int i;
    for(i = 0; i < qtd; i++){
        alunos[i] = LeAluno();
    }

    //Organizacao em ordem crescente de matricula
    int j;
    tAluno temp;
    for(i = 0; i < qtd; i++){
        for(j = i; j < qtd; j++){
            if(ComparaMatricula(alunos[j], alunos[i]) == -1){
                temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
    //

    for(i = 0; i < qtd; i++){
        if(VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
    }

    return 0;
}