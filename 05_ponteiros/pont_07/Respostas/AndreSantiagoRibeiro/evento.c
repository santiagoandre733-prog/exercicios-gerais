#include <stdio.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos){
    scanf(" %[^\n]\n", eventos[*numEventos].nome);
    scanf("%d %d %d ", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
    (*numEventos)++;
    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos){
    printf("Eventos cadastrados:\n");
    int i;
    for(i = 0; i < *numEventos; i++){
        printf("%d - %s - %02d/%02d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int n;
    scanf("%d ", &n);
    scanf("%d %d %d ", &eventos[n].dia, &eventos[n].mes, &eventos[n].ano);
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    Evento temp;
    temp = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = temp;
}