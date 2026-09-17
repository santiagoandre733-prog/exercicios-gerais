#include <stdio.h>
#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData( tData *data ){
    int dia, mes, ano;
    scanf("%d %d %d ", &dia, &mes, &ano);
    if(mes > 12){
        mes = 12;
    }
    InicializaDataParam(dia, mes, ano, data);
    if(dia > InformaQtdDiasNoMes(data)){
        dia = InformaQtdDiasNoMes(data);
        InicializaDataParam(dia, mes, ano, data);
    }
}

void ImprimeData( tData *data ){
    printf("'%02d/%02d/%d'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data ){
    if(data->ano %400 == 0){
        return 1;
    }
    if(data->ano %100 == 0){
        return 0;
    }
    if(data->ano %4 == 0){
        return 1;
    }
    return 0;
}

int InformaQtdDiasNoMes( tData *data ){
    int mes = data->mes;
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
    }
    else if(mes == 2){
        if(EhBissexto(data)){
            return 29;
        }
        else {
            return 28;
        }
    }

    return 30;
}

void AvancaParaDiaSeguinte( tData *data ){
    data->dia++;
    if(data->dia > InformaQtdDiasNoMes(data)){
        data->dia = 1;
        data->mes++;
        if(data->mes > 12){
            data->mes = 1;
            data->ano++;
        }
    }
}

int EhIgual( tData *data1, tData *data2 ){
    return data1->dia == data2->dia && data1->mes == data2->mes && data1->ano == data2->ano;
}