#include <string.h>
#include <stdio.h>
#include "area.h"

Area lerArea(){
    Area area;
    scanf("%[^\n]\n", area.nome);
    scanf("%[^\n]\n ", area.id);
    scanf("%d ", &area.capacidade);
    return area;
}

void imprimeArea(Area a){
    printf("Nome: %s\nId: %s\nCapacidade: %d convidado(s)\n", a.nome, a.id, a.capacidade);
}

int comparaArea(Area a1, Area a2){
    if(strcmp(a1.id, a2.id) == 0){
        return 1;
    }
    return 0;
}

int verificaIdArea(Area a, char *id){
    if(strcmp(a.id, id) == 0){
        return 1;
    }
    return 0;
}

int getCapacidadeArea(Area a){
    return a.capacidade;
}