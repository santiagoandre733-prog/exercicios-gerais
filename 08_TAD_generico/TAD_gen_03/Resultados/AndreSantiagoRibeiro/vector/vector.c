#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector {
    data_type *v;
    int qtd;
};

Vector *VectorConstruct(){
    Vector *v = (Vector*) calloc(1, sizeof(Vector));
    return v;
}

void VectorPushBack(Vector *v, data_type val){
    v->v = realloc(v->v, (v->qtd + 1)*sizeof(data_type));
    v->v[v->qtd] = val;
    v->qtd += 1;
}

data_type VectorGet(Vector *v, int i){
    return v->v[i];
}

int VectorSize(Vector *v){
    return v->qtd;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    int i;
    for(i = 0; i < v->qtd; i++){
        destroy(v->v[i]);
    }
    free(v->v);
    free(v);
}