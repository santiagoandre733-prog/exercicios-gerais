#include <stdio.h>
#include "calculadora.h"

float Soma(float a, float b);
float Subtracao(float a, float b);
float Multiplicacao(float a, float b);
float Divisao(float a, float b);

int main(){
    char c;
    float a, b;
    while(1){
        scanf("%c ", &c);
        if(c == 'f'){
            break;
        }

        scanf("%f %f ", &a, &b);
        if(c == 'a'){
            printf("%.2f + %.2f = %.2f\n", a, b, Calcular(a, b, Soma));
        }
        else if(c == 's'){
            printf("%.2f - %.2f = %.2f\n", a, b, Calcular(a, b, Subtracao));
        }
        else if(c == 'm'){
            printf("%.2f x %.2f = %.2f\n", a, b, Calcular(a, b, Multiplicacao));
        }
        else if(c == 'd'){
            printf("%.2f / %.2f = %.2f\n", a, b, Calcular(a, b, Divisao));
        }
    }

    return 0;
}

float Soma(float a, float b){
    return a + b;
}

float Subtracao(float a, float b){
    return a - b;
}

float Multiplicacao(float a, float b){
    return a*b;
}

float Divisao(float a, float b){
    return a/b;
}