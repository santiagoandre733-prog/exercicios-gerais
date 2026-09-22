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
    printf("\nDepartamento: %s\n\tDiretor: %s\n\t1o curso: %s\n\tMedia do 1o curso: %d\n\t2o curso: %s\n\tMedia do 2o curso: %d\n\t3o curso: %s\n\tMedia do 3o curso: %d\n\tMedia dos cursos: %.2f",
    depto.nome, depto.diretor, depto.curso1, depto.m1, depto.curso2, depto.m2, depto.curso3, depto.m3, (float)(depto.m1 + depto.m2 + depto.m3)/3);
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    tDepartamento temp;
    int i, j, iMaior;
    float mediaMaior, mediaI;
    for(i = 0; i < num_deptos; i++){
        for(j = i + 1; j < num_deptos; j++){
            float media = (float)(vetor_deptos[j].m1 + vetor_deptos[j].m2 + vetor_deptos[j].m3)/3;
            if(j == i){
                iMaior = j;
                mediaMaior = media;
            }
            else if(media > mediaMaior){
                iMaior = j;
                mediaMaior = media;
            }
        }

        mediaI = (float)(vetor_deptos[i].m1 + vetor_deptos[i].m2 + vetor_deptos[i].m3)/3;
        if(mediaMaior > mediaI){
            temp = vetor_deptos[i];
            vetor_deptos[i] = vetor_deptos[iMaior];
            vetor_deptos[iMaior] = temp;
        }
    }
}