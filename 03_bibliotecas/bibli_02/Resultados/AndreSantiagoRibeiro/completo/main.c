#include "matrix_utils.h"
#include <stdio.h>

void ImprimeMenu();
void ImprimeErro(int n);

int main(){
    int rows1, cols1, rows2, cols2, opcao;

    //Leituras iniciais
    scanf("%d %d ", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d ", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    //Menu
    while(1){
        ImprimeMenu();
        scanf("%d ", &opcao);

        if(opcao == 1){
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            else {
                ImprimeErro(1);
            }
        }
        else if(opcao == 2){
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            else {
                ImprimeErro(1);
            }
        }
        else if(opcao == 3){
            if(possible_matrix_multiply(cols1, rows2)){
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
            }
            else {
                ImprimeErro(2);
            }
        }
        else if(opcao == 4){
            int scalar, n;
            scanf("%d %d ", &scalar, &n);
            if(n == 1){
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            }
            else if(n == 2){
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            }
        }
        else if(opcao == 5){
            int result1[cols1][rows1];
            int result2[cols2][rows2];

            transpose_matrix(rows1, cols1, matrix1, result1);
            matrix_print(cols1, rows1, result1);
            printf("\n");
            transpose_matrix(rows2, cols2, matrix2, result2);
            matrix_print(cols2, rows2, result2);
        }
        if(opcao == 6){
            break;
        }
        printf("\n");
    }

    return 0;
}

void ImprimeMenu(){
    printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
}

void ImprimeErro(int n){
    if(n == 1){
        printf("Erro: as dimensoes da matriz nao correspondem\n");
    }
    else if(n == 2){
        printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
    }
}