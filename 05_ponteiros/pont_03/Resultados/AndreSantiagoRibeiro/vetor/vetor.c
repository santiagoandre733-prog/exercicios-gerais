#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int * vet, int tam){
    while(tam){
        scanf("%d ", vet);
        vet++;
        tam--;
    }
}

void ImprimeDadosDoVetor(int * n, int tam){
    while(tam){
        printf("%d ", *n);
        n++;
        tam--;
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    int *menor, flag = 0;
    while(tam){
        if(!flag){
            menor = vet;
            flag = 1;
        }
        else if(*vet < *menor){
            menor = vet;
        }
        vet++;
        tam--;
    }
    if(*menor < *paraTrocar){
        int temp = *menor;
        *menor = *paraTrocar;
        *paraTrocar = temp;
    }
}

void OrdeneCrescente(int * vet, int tam){
    while(tam){
        TrocaSeAcharMenor(vet, tam, vet);
        vet++;
        tam--;
    }
}