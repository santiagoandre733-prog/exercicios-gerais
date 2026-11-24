#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "histograma.h"

struct tHistograma {
    int *pixelIntervalos;
    int numIntervalos;
    int tamanhoIntervalo;
};

Histograma *CalcularHistograma(Imagem *img, int nIntervalos){
    Histograma *h = malloc(sizeof(Histograma));
    h->numIntervalos = nIntervalos;
    float n = (float)256/nIntervalos;
    if((n - (int)n)){
        h->tamanhoIntervalo = (int)n + 1;
    }
    else {
        h->tamanhoIntervalo = (int)n;
    }
    h->pixelIntervalos = calloc(1, nIntervalos*sizeof(int));

    void* matriz = ObterDadosImagem(img);
    int linhas = ObterAlturaImagem(img);
    int colunas = ObterLarguraImagem(img);
    int i, j, k;
    int pixel;
    if(ObterTipoImagem(img) == INT){
        for(i = 0; i < linhas; i++){
            for(j = 0; j < colunas; j++){
                pixel = ((int*)matriz)[i*colunas + j];
                for(k = 0; k < nIntervalos; k++){
                    if(pixel >= k*h->tamanhoIntervalo && pixel < (k + 1)*h->tamanhoIntervalo){
                        h->pixelIntervalos[k] += 1;
                    }
                }
            }
        }
    }
    else if(ObterTipoImagem(img) == FLOAT){
        for(i = 0; i < linhas; i++){
            for(j = 0; j < colunas; j++){
                pixel = ((float*)matriz)[i*colunas + j]*255;
                for(k = 0; k < nIntervalos; k++){
                    if(pixel >= k*h->tamanhoIntervalo && pixel < (k + 1)*h->tamanhoIntervalo){
                        h->pixelIntervalos[k] += 1;
                    }
                }
            }
        }
    }

    return h;
}

void MostrarHistograma(Histograma *histograma){
    int i;
    for(i = 0; i < histograma->numIntervalos; i++){
        printf("[%d, %d): %d\n", i*histograma->tamanhoIntervalo, (i + 1)*histograma->tamanhoIntervalo, histograma->pixelIntervalos[i]);
    }
}

void DestruirHistograma(Histograma *histograma){
    free(histograma->pixelIntervalos);
    free(histograma);
}