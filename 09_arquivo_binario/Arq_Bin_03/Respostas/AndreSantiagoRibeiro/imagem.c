#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"

struct tImagem {
    int linhas, colunas;
    int bytesLidos;
    int tipo;
    void* matriz;
};

Imagem *LerImagem(const char *caminho){
    FILE *f = fopen(caminho, "rb");
    Imagem* im = malloc(sizeof(Imagem));

    int soma = 0;
    soma += fread(&im->linhas, sizeof(int), 1, f)*sizeof(int);
    soma += fread(&im->colunas, sizeof(int), 1, f)*sizeof(int);
    soma += fread(&im->tipo, sizeof(int), 1, f)*sizeof(int);

    int i, j;
    if(im->tipo == FLOAT){
        im->matriz = malloc(im->linhas*im->colunas*sizeof(float));

        for(i = 0; i < im->linhas; i++){
            for(j = 0; j < im->colunas; j++){
                soma += fread(im->matriz + (im->colunas*i + j)*sizeof(float), sizeof(float), 1, f)*sizeof(float);
            }
        }
    }
    else if(im->tipo == INT){
        im->matriz = malloc(im->linhas*im->colunas*sizeof(int));

        for(i = 0; i < im->linhas; i++){
            for(j = 0; j < im->colunas; j++){
                soma += fread(im->matriz + (im->colunas*i + j)*sizeof(int), sizeof(int), 1, f)*sizeof(int);
            }
        }
    }
    im->bytesLidos = soma;

    return im;
}

void DestruirImagem(Imagem *img){
    free(img->matriz);
    free(img);
}

int ObterNumeroBytesLidos(Imagem *img){
    return img->bytesLidos;
}

void ImprimirImagem(Imagem *img){
    int i, j;

    if(img->tipo == FLOAT);
    for(i = 0; i < img->linhas; i++){
        for(j = 0; j < img->colunas; j++){
            printf("%.2f ",)
        }
    }
}