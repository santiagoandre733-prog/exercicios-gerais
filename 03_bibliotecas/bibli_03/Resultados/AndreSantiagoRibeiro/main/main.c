#include "data.h"
#include <stdio.h>

int main(){
    int dia1, mes1, ano1, dia2, mes2, ano2;
    scanf("%d/%d/%d ", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d ", &dia2, &mes2, &ano2);

    if(!verificaDataValida(dia1, mes1, ano1) || !verificaDataValida(dia2, mes2, ano2)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    else {
        printf("Primeira data: ");
        imprimeDataExtenso(dia1, mes1, ano1);
        printf("Segunda data: ");
        imprimeDataExtenso(dia2, mes2, ano2);

        int n;
        n = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
        if(n == 1){
            printf("A segunda data eh mais antiga\n");
        }
        else if(n == -1){
            printf("A primeira data eh mais antiga\n");
        }
        else {
            printf("As datas sao iguais\n");
        }

        printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));
    }
    return 0;
}