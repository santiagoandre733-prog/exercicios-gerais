#include <stdio.h>
#include "banco.h"

int main(){
    char acao;
    tBanco *banco = CriaBanco();
    while(1){
        scanf("%c ", &acao);
        if(acao == 'A'){
            AbreContaBanco(banco);
        }
        else if(acao == 'D'){
            DepositoContaBanco(banco);
        }
        else if(acao == 'S'){
            SaqueContaBanco(banco);
        }
        else if(acao == 'T'){
            TransferenciaContaBanco(banco);
        }
        else if(acao == 'R'){
            ImprimeRelatorioBanco(banco);
        }
        else if(acao == 'F'){
            break;
        }
    }
    DestroiBanco(banco);
    return 0;
}