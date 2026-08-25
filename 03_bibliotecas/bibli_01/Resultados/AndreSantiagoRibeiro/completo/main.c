#include "esfera_utils.h"
#include <stdio.h>

int main(){
    int n;
    scanf("%f", &n);
    printf("Area: %.2f\n", calcula_area(n));
    printf("Volume: %.2f\n", calcula_volume(n));
}