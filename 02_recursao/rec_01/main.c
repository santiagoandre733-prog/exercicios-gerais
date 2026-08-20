#include <stdio.h>

void ImprimeInvertido(char* string, int n);

int main(){
    char * string;

    while (scanf("%s", string) == 1){
        ImprimeInvertido(string, 0);
        printf(" ");
    }

    return 0;
}

void ImprimeInvertido(char* string, int n){
    if(string[n] == 0){
        return;
    }

    ImprimeInvertido(string, n + 1);

    printf("%c", string[n]);
}