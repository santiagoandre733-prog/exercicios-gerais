#include <stdio.h>
#include "imagem.h"

int main(){
    char caminho[50];
    scanf("%[^\n]\n", caminho);
    Imagem *im = LerImagem(caminho);
    printf("Numero de bytes lidos: %d\n", ObterNumeroBytesLidos(im));
    ImprimirImagem(im);
    DestruirImagem(im);
    return 0;
}