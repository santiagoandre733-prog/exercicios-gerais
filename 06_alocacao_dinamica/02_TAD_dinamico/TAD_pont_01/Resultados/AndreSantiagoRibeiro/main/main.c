#include "jogo.h"
#include <stdio.h>

int main(){
    while(1){
        tJogo *jogo = CriaJogo();
        ComecaJogo(jogo);
        DestroiJogo(jogo);
        if(!ContinuaJogo()){
            break;
        }
    }

    return 0;
}