#include "reserva.h"

Reserva criaReserva(Morador morRes, Area aRes, Data dRes, int qtdConvidados){
    Reserva r;
    r.morador = morRes;
    r.area = aRes;
    r.data = dRes;
    r.qtdConvidados = qtdConvidados;

    return r;
}

int verificaSolicitacaoReserva(Reserva *agendaReservas, int nRes, Morador morRes, Area aRes, Data dRes, int qtdConvidados){
    int i;
    for(i = 0; i < nRes; i++){
        if((comparaMorador(agendaReservas[i].morador, morRes) || comparaArea(agendaReservas[i].area, aRes)) && comparaData(agendaReservas[i].data, dRes)){
            return 0;
        }
    }

    if(qtdConvidados > getCapacidadeArea(aRes)){
        return 0;
    }
    if(calculaIdadeMorador(morRes, dRes) < 18){
        return 0;
    }

    return 1;
}

void imprimeReserva(Reserva r){
    printf("--------- RESERVA -----------\n");
    printf("Morador: \n");
    imprimeMorador(r.morador);
    printf("\nArea reservada: \n");
    imprimeArea(r.area);
    printf("Data da reserva: ");
    imprimeData(r.data);
    printf("\nQuantidade de convidados: %d\n", r.qtdConvidados);
    int n;
    printf("Taxa de ocupação: %d%%\n", (int)((float)r.qtdConvidados/(float)getCapacidadeArea(r.area) * 100));
    printf("------------------------------\n");
}