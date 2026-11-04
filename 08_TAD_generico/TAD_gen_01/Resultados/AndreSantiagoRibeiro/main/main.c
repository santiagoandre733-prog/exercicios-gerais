#include <stdio.h>
#include "tadgen.h"

int main(){
    printf("tad_gen_01\nDigite o tipo e numero de elementos: \n");
    int tipo, tam;
    scanf("%d %d ", &tipo, &tam);
    tGeneric *g = CriaGenerico(tipo, tam);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);

    return 0;
}