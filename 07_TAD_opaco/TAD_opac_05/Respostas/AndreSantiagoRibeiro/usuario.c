#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_PADRAO_STRING 50

struct Usuario {
    char *nome;
    int cpf;
};

tUsuario *CriaUsuario(){
    tUsuario *u = (tUsuario*) malloc(sizeof(tUsuario));
    if(u == NULL){
        exit(1);
    }

    return u;
}

void DestroiUsuario(tUsuario *user){
    free(user->nome);
    free(user);
}

void LeUsuario(tUsuario *user){
    user->nome = (char*) malloc(TAM_PADRAO_STRING * sizeof(char));
    scanf("%s %d ", user->nome, &user->cpf);
}

void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\nCPF: %d\n", user->nome, user->cpf);
}