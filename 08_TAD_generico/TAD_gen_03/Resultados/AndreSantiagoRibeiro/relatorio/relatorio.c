#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"

void ImprimeRelatorio(Vector *alunos){
    int i;
    float somaN = 0;
    int somaA = 0, somaM = 0, somaF = 0, somaO = 0;
    for(i = 0; i < VectorSize(alunos); i++){
        char c = GetGeneroAluno(VectorGet(alunos, i));
        if(c == 'M') somaM++;
        else if(c == 'F') somaF++;
        else if(c == 'O') somaO++;
        int n = GetNotaAluno(VectorGet(alunos, i));
        somaN += n;
        if(n >= 6) somaA++;
    }

    printf("Media das notas: %.2f\n", somaN/VectorSize(alunos));
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (float)somaA/VectorSize(alunos)*100);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", (float)somaM/VectorSize(alunos)*100);
    printf("Feminino: %.2f%%\n", (float)somaF/VectorSize(alunos)*100);
    printf("Outro: %.2f%%\n", (float)somaO/VectorSize(alunos)*100);
}