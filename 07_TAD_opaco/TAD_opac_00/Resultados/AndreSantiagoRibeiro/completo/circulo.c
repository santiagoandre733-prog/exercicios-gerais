#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>


struct circulo{
    tPonto centro;
    float raio;
};

tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo circulo = (tCirculo) malloc(sizeof(struct circulo));
    circulo->centro = Pto_Cria(x, y);
    circulo->raio = r;

    return circulo;
}

void Circulo_Apaga (tCirculo c){
    Pto_Apaga(c->centro);
    free(c);
}

tPonto Circulo_Acessa_Centro (tCirculo c){
    return c->centro;
}

float Circulo_Acessa_Raio (tCirculo c){
    return c->raio;
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p){
    c->centro = p;
}

void Circulo_Atribui_Raio (tCirculo c, float r){
    c->raio = r;
}

int Circulo_Interior (tCirculo c, tPonto p){
    return Pto_Distancia(c->centro, p) <= c->raio;
}