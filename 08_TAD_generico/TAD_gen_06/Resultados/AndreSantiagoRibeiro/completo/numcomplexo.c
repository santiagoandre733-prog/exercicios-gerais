#include <stdio.h>
#include <stdlib.h>
#include "numcomplexo.h"

struct complexo {
    float real, imag;
};

tNumComplexo* CriaNumComplexo(float real, float imag){
    tNumComplexo *n = malloc(sizeof(tNumComplexo));
    n->real = real;
    n->imag = imag;
    return n;
}

float PegaParteImagComplexo(tNumComplexo *cplx){
    return cplx->imag;
}

float PegaParteRealComplexo(tNumComplexo *cplx){
    return cplx->real;
}

void ImprimeNumeroComplexo(tNumComplexo *cplx){
    printf("%.2f + i%.2f", cplx->real, cplx->imag);
}

void DestroiNumeroComplexo(tNumComplexo *cplx){
    free(cplx);
}

int RetornaNumBytesComplexo(){
    return sizeof(tNumComplexo);
}

tNumComplexo* SomaComplexos(tNumComplexo* n1, tNumComplexo *n2){
    tNumComplexo *rtn = CriaNumComplexo(n1->real + n2->real, n1->imag + n2->imag);
    return rtn;   
}

tNumComplexo* MultComplexos(tNumComplexo* n1, tNumComplexo* n2){
    tNumComplexo* rtn = CriaNumComplexo(n1->real*n2->real - n1->imag*n2->imag, n1->real*n2->imag + n2->real*n1->imag);
    return rtn;
}