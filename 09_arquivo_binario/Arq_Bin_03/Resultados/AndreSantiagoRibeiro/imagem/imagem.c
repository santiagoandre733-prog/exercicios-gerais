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
    soma += fread(&im->linhas, sizeof(int), 1, f);
    soma += fread(&im->colunas, sizeof(int), 1, f);
    soma += fread(&im->tipo, sizeof(int), 1, f);

    int i, j;
    if(im->tipo == FLOAT){
        im->matriz = malloc(im->linhas*im->colunas*sizeof(float));

        //soma += fread(im->matriz, sizeof(float), (im->linhas*im->colunas - 1)*sizeof(float), f);
        for(i = 0; i < im->linhas; i++){
            for(j = 0; j < im->colunas; j++){
                soma += fread(im->matriz + (im->colunas*i + j)*sizeof(float), sizeof(float), 1, f);
            }
        }
    }
    else if(im->tipo == INT){
        im->matriz = malloc(im->linhas*im->colunas*sizeof(int));

        //soma += fread(im->matriz, sizeof(int), (im->linhas*im->colunas - 1)*sizeof(int), f);
        for(i = 0; i < im->linhas; i++){
            for(j = 0; j < im->colunas; j++){
                soma += fread(im->matriz + (im->colunas*i + j)*sizeof(int), sizeof(int), 1, f);
            }
        }
    }
    im->bytesLidos = soma;

    fclose(f);
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

    if(img->tipo == FLOAT){
        for(i = 0; i < img->linhas; i++){
            for(j = 0; j < img->colunas; j++){
                printf("%.2f ",((float*)img->matriz)[i*img->colunas + j]);
            }
            printf("\n");
        }
    }
    else if(img->tipo == INT){
        for(i = 0; i < img->linhas; i++){
            for(j = 0; j < img->colunas; j++){
                printf("%d ",((int*)img->matriz)[i*img->colunas + j]);
            }
            printf("\n");
        }
    }
}