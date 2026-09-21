#include <stdio.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos){
    if(*numEventos == MAX_EVENTOS){
        printf("Limite de eventos atingido!\n");
        return;
    }
    scanf(" %[^\n]\n", eventos[*numEventos].nome);
    scanf("%d %d %d ", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
    (*numEventos)++;
    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos){
    if(*numEventos == 0){
        printf("Nenhum evento cadastrado.\n");
        return;
    }
    printf("Eventos cadastrados:\n");
    int i;
    for(i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int n;
    scanf("%d ", &n);
    if(n >= *numEventos){
        printf("Indice invalido!\n");
        return;
    }
    scanf("%d %d %d ", &eventos[n].dia, &eventos[n].mes, &eventos[n].ano);
    printf("Data modificada com sucesso!\n");
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    if(*indiceA >= *numEventos || *indiceB >= *numEventos){
        printf("Indices invalidos!\n");
        return;
    }
    Evento temp;
    temp = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = temp;
    printf("Eventos trocados com sucesso!\n");
}