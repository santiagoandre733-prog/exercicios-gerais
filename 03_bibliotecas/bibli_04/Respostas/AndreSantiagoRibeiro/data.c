#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano){
    if((mes < 1) || (mes > 12)){
        return 0;
    }
    if((dia < 1) || (dia > numeroDiasMes(mes, ano))){
        return 0;
    }
    return 1;
}

void imprimeData(int dia, int mes, int ano){
    printf("%02d/%02d/%d", dia, mes, ano);
}

void imprimeMesExtenso(int mes){
    if(mes == 1){
        printf("Janeiro");
    }
    else if(mes == 2){
        printf("Fevereiro");
    }
    else if(mes == 3){
        printf("Marco");
    }
    else if(mes == 4){
        printf("Abril");
    }
    else if(mes == 5){
        printf("Maio");
    }
    else if(mes == 6){
        printf("Junho");
    }
    else if(mes == 7){
        printf("Julho");
    }
    else if(mes == 8){
        printf("Agosto");
    }
    else if(mes == 9){
        printf("Setembro");
    }
    else if(mes == 10){
        printf("Outubro");
    }
    else if(mes == 11){
        printf("Novembro");
    }
    else if(mes == 12){
        printf("Dezembro");
    }
    return;
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
    return;
}

int verificaBissexto(int ano){
    if(ano%400 == 0){
        return 1;
    }
    if(ano%100 == 0){
        return 0;
    }
    if(ano%4 == 0){
        return 1;
    }
    return 0;
}

int numeroDiasMes(int mes, int ano){
    if((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)){
        return 31;
    }
    if(mes == 2){
        if(verificaBissexto(ano)){
            return 29;
        }
        else {
            return 28;
        }
    }
    return 30;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2){
        return 1;
    }
    else if(ano2 > ano1){
        return -1;
    }
    else {
        if(mes1 > mes2){
            return 1;
        }
        else if(mes2 > mes1){
            return -1;
        }
        else{
            if(dia1 > dia2){
                return 1;
            }
            else if(dia2 > dia1){
                return -1;
            }
        }
    }
    return 0;
}

int calculaDiasAteMes(int mes, int ano){
    int i, soma = 0;

    for(i = 1; i < mes; i++){
        soma += numeroDiasMes(i, ano);
    }
    return soma;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int difDia, somaDia = 0, i;
    int dias1, dias2;

    dias1 = calculaDiasAteMes(mes1, ano1) + dia1;
    dias2 = calculaDiasAteMes(mes2, ano2) + dia2;

    if(ano1 > ano2){
        for(i = ano2; i < ano1; i++){
            if(verificaBissexto(i)){
                somaDia += 366;
            }
            else {
                somaDia += 365;
            }
        }
        difDia = dias1 - dias2;
    }
    else if(ano2 > ano1){
        for(i = ano1; i < ano2; i++){
            if(verificaBissexto(i)){
                somaDia += 366;
            }
            else {
                somaDia += 365;
            }
        }
        difDia = dias2 - dias1;
    }
    else {
        if(dias1 > dias2){
            difDia = dias1 - dias2;
        }
        else if(dias2 > dias1){
            difDia = dias2 - dias1;
        }
        else {
            difDia = 0;
        }
    }

    somaDia += difDia;

    return somaDia;
}

void imprimeProximaData(int dia, int mes, int ano){
    dia++;
    if(dia > numeroDiasMes(mes, ano)){
        dia = 1;
        mes++;
        if(mes > 12){
            mes = 1;
            ano++;
        }
    }

    imprimeData(dia, mes, ano);
    return;
}