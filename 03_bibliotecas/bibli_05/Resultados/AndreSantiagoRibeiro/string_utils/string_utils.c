#include "string_utils.h"
#include <string.h>
#include <stdio.h>

int string_length(char *str){
    return strlen(str);
}

void string_copy(char *src, char *dest){
    sprintf(dest, "%s", src);
}

void string_upper(char *str){
    int i;

    for(i = 0; i < string_length(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
}

void string_lower(char *str){
    int i;

    for(i = 0; i < string_length(str); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
    }
}

void string_reverse(char *str){
    int i;
    int tam = string_length(str);
    char temp;

    for(i = 0; i < tam/2; i++){
        temp = str[i];
        str[i] = str[tam - 1 - i];
        str[tam - 1 - i] = temp;
    }
}