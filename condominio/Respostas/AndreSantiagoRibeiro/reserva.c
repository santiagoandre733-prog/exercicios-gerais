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
        if(comparaMorador(agendaReservas[i].morador, morRes) || comparaArea(agendaReservas[i].area, aRes)){
            return 0;
        }
    }

    if(qtdConvidados > getCapacidadeArea(aRes)){
        return 0;
    }
    
}