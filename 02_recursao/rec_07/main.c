#include <stdio.h>

int somaDigitos(int n);

int main(){
    int n;

    scanf("%d", &n);
    printf("%d\n", somaDigitos(n));

    return 0;
}

int somaDigitos(int n){
    if(n / 10 == 0){
        return n;
    }

    return n%10 + somaDigitos(n/10);
}