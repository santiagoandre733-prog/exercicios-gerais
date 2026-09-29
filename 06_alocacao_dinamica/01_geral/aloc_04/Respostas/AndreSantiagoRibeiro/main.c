#include <stdio.h>
#include "utils_char2.h"

int main(){
    int tamanho = TAM_PADRAO;
    char *v = CriaVetorTamPadrao();
    v = LeVetor(v, &tamanho);
    ImprimeString(v);
    LiberaVetor(v);

    return 0;
}