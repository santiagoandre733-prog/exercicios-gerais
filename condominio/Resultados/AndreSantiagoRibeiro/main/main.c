#include "reserva.h"
#include <stdio.h>

int ExisteMorador(Morador * m, int qtdM, char * cpf);
int ExisteArea(Area * a, int qtdA, char * id);
Morador ObtemMoradorPeloCPF(Morador * m, int qtdM, char * cpf);
Area ObtemAreaPeloID(Area * a, int qtdA, char * id);

int main(){
    int qtdA, qtdM, qtdR, i;

    scanf("%d ", &qtdA);
    Area a[qtdA];
    for(i = 0; i < qtdA; i++){
        a[i] = lerArea();
    }
    scanf("%d ", &qtdM);
    Morador m[qtdM];
    for(i = 0; i < qtdM; i++){
        m[i] = lerMorador();
    }
    scanf("%d ", &qtdR);
    Reserva r[qtdR];
    for(i = 0; i < qtdR; i++){
        char id[MAX_TAM_ID];
        char cpf[MAX_TAM_CPF];
        Data d;
        int qtdConvidados;
        scanf("%[^\n]\n", id);
        scanf("%[^\n]\n", cpf);
        d = lerData();
        scanf("%d ", &qtdConvidados);
        if(ExisteMorador(m, qtdM, cpf) && ExisteArea(a, qtdA, id)){

            if(verificaSolicitacaoReserva(r, i, ObtemMoradorPeloCPF(m, qtdM, cpf), ObtemAreaPeloID(a, qtdA, id), d, qtdConvidados)){
                r[i] = criaReserva(ObtemMoradorPeloCPF(m, qtdM, cpf), ObtemAreaPeloID(a, qtdA, id), d, qtdConvidados);
                imprimeReserva(r[i]);
            }

        }
    }

    return 0;
}

Morador ObtemMoradorPeloCPF(Morador * m, int qtdM, char * cpf){
    int i;
    for(i = 0; i < qtdM; i++){
        if(verificaCPFMorador(m[i], cpf)){
            return m[i];
        }
    }
}
int ExisteMorador(Morador * m, int qtdM, char * cpf){
     int i;
    for(i = 0; i < qtdM; i++){
        if(verificaCPFMorador(m[i], cpf)){
            return 1;
        }
    }
    return 0;
}

Area ObtemAreaPeloID(Area * a, int qtdA, char * id){
    int i;
    for(i = 0; i < qtdA; i++){
        if(verificaIdArea(a[i], id)){
            return a[i];
        }
    }
}
int ExisteArea(Area * a, int qtdA, char * id){
    int i;
    for(i = 0; i < qtdA; i++){
        if(verificaIdArea(a[i], id)){
            return 1;
        }
    }
    return 0;
}