#include "morador.h"
#include <stdio.h>
#include <string.h>

Morador lerMorador(){
    Morador m;
    scanf("%[^\n]\n", &m.nome);
    scanf("%[^\n]\n", &m.cpf);
    m.dataNasc = lerData();
    scanf("\n");
    scanf("%[^\n]\n", &m.idResidencia);

    return m;
}

void imprimeMorador(Morador m){
    printf("Nome: %s\nCPF: %s\nData de Nascimento: ", m.nome, m.cpf);
    imprimeData(m.dataNasc);
    printf("Residência: %s\n", m.idResidencia);
}

int comparaMorador(Morador m1, Morador m2){
    if(strcmp(m1.cpf, m2.cpf) == 0){
        return 1;
    }
    return 0;
}

int verificaCPFMorador(Morador m1, char *cpf){
    if(strcmp(m1.cpf, cpf) == 0){
        return 1;
    }
    return 0;
}

int calculaIdadeMorador(Morador m, Data dataRef){
    return calcularDiffAnosData(m.dataNasc, dataRef);
}