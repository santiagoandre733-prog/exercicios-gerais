#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"

#define TAM_MAX_STRING 50

struct impr {
    char msg[TAM_MAX_STRING];
};

tImpr* CriaTarefaImprimir(char *msg){
    tImpr *impr = malloc(sizeof(tImpr));
    strcpy(impr->msg, msg);
    return impr;
}

void ExecutaTarefaImprimir(void *imp){
    printf("\n%s", ((tImpr*)imp)->msg);
}

void DestroiTarefaImprimir(void *imp){
    free((tImpr*)imp);
}