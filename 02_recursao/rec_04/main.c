#include <stdio.h>
#include <string.h>

int palindromo(char *string, int tamanho, int n);

int main(){
    char* string;

    while(scanf("%s", string) == 1){

        if(palindromo(string, strlen(string), 0)){
            printf("SIM");
        }
        else {
            printf("NAO");
        }
        printf("\n");
    }

    return 0;
}

int palindromo(char *string, int tamanho, int n){
    if(tamanho == 1){
        if(string[n] == string[tamanho - 1]){
            return 1;
        }
        return 0;
    }

    if(string[n] == string[tamanho - 1]){
        return palindromo(string, tamanho - 1, n + 1);
    }
    else {
        return 0;
    }
}