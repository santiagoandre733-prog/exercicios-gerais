#include "matrix_utils.h"
#include <stdio.h>

void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int i, j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf("%d ", &matrix[i][j]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]){
    int i, j;

    for(i = 0; i < rows; i++){
        printf("|");
        for(j = 0; j < cols; j++){
            printf("%d", matrix[i][j]);
            if(j != cols - 1){
                printf(" ");
            }
        }
        printf("|\n");
    }
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    if((rows1 == rows2) && (cols1 == cols2)){
        return 1;
    }
    return 0;
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    if((rows1 == rows2) && (cols1 == cols2)){
        return 1;
    }
    return 0;
}

int possible_matrix_multiply(int cols1, int rows2){
    if(cols1 == rows2){
        return 1;
    }
    return 0;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int i, j;

    for(i = 0; i < rows1; i++){
        for(j = 0; j < cols1; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    int i, j;

    for(i = 0; i < rows1; i++){
        for(j = 0; j < cols1; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
