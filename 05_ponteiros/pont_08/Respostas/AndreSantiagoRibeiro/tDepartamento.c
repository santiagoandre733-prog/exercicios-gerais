#include "tDepartamento.h"
#include <stdio.h>
#include <string.h>

tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento departamento;
    strcpy(departamento.curso1, curso1);
    strcpy(departamento.curso2, curso2);
    strcpy(departamento.curso3, curso3);
    strcpy(departamento.nome, nome);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    strcpy(departamento.diretor, diretor);

    return departamento;
}

void ImprimeAtributosDepartamento(tDepartamento depto){
    printf("Departamento: %s\n\tDiretor: %s\n\t1o curso: %s\n\tMedia do 1o curso: %d\n\t2o curso: %s\n\tMedia do 2o curso: %d\n\t3o curso: %s\n\tMedia do 3o curso: %d\n\tMedia dos cursos: %.2f\n",
    depto.nome, depto.diretor, depto.curso1, depto.m1, depto.curso2, depto.m2, depto.curso3, depto.m3, (float)(depto.m1 + depto.m2 + depto.m3)/3);
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    tDepartamento temp;
    int i, j, iMenor;
    for(i = 0; i < num_deptos; i++){
        for(j = i + 1; j < num_deptos; j++){
            
        }
    }
}