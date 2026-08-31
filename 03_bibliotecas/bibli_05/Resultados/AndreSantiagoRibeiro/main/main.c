#include "string_utils.h"
#include <string.h>
#include <stdio.h>

void ImprimeMenu();

int main(){
    char str[1000];
    char copy[1000];
    int n;
    scanf("%[^\n]\n", str);
    
    while(1){
        ImprimeMenu();
        scanf("%d ", &n);
        if(n == 1){
            printf("Tamanho da string: %d\n", string_length(str));
        }
        else if(n == 2){
            string_copy(str, copy);
            printf("String copiada: %s\n", copy);
        }
        else if(n == 3){
            string_upper(str);
            printf("String convertida para maiusculas: %s\n", str);
        }
        else if(n == 4){
            string_lower(str);
            printf("String convertida para minusculas: %s\n", str);
        }
        else if(n == 5){
            string_reverse(str);
            printf("String invertida: %s\n", str);
        }
        if(n == 6){
            break;
        }
    }
    
    return 0;
}

void ImprimeMenu(){
    printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
    return;
}