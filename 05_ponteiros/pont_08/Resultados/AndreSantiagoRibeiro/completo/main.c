#include <stdio.h>
#include "tDepartamento.h"

int main(){
    int qtdDep;
    scanf("%d ", &qtdDep);
    tDepartamento departamentos[qtdDep];
    int i;
    for(i = 0; i < qtdDep; i++){
        char nome[STRING_MAX];
        char diretor[STRING_MAX];
        char curso1[STRING_MAX];
        char curso2[STRING_MAX];
        char curso3[STRING_MAX];
        int m1, m2, m3;
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);
        scanf("%[^\n]\n", curso1);
        scanf("%[^\n]\n", curso2);
        scanf("%[^\n]\n", curso3);
        scanf("%d %d %d ", &m1, &m2, &m3);
        if(m1 < 0 || m1 > 10 || m2 < 0 || m2 > 10 || m3 < 0 || m3 > 10){
            printf("\nDigite um departamento com médias válidas");
            i--;
        }
        else {
            departamentos[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
        }
    }

    OrdenaDepartamentosPorMedia(departamentos, qtdDep);
    for(i = 0; i < qtdDep; i++){
        ImprimeAtributosDepartamento(departamentos[i]);
    }

    return 0;
}