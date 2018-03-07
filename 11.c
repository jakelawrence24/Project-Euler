/*
 * =====================================================================================
 *
 *       Filename:  11.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/06/2018 20:39:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christopher Lawrence (clawrence), jake.lawrence@temple.edu
 *        Company:  Temple University
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <limits.h>

#define ROWS 20
#define COLS 20

int calculateRight(int matrix[ROWS][COLS], int row, int col, int distance);
int calculateLeft(int matrix[ROWS][COLS], int row, int col, int distance);
int calculateUp(int matrix[ROWS][COLS], int row, int col, int distance);
int calculateDown(int matrix[ROWS][COLS], int row, int col, int distance);
int calculateDiagonalDR(int matrix[ROWS][COLS], int row, int col, int distance);
int calculateDiagonalUL(int matrix[ROWS][COLS], int row, int col, int distance);
int calculateDiagonalDL(int matrix[ROWS][COLS], int row, int col, int distance);
int calculateDiagonalUR(int matrix[ROWS][COLS], int row, int col, int distance);

int main(){

	int matrix[ROWS][COLS] = {{8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
                              {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
                              {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
                              {52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
                              {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
                              {24, 47, 32, 60, 99, 03, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
                              {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
                              {67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
                              {24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
                              {21, 36, 23, 9, 75, 00, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
                              {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14, 9, 53, 56, 92},
                              {16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
                              {86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
                              {19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
                              {4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
                              {88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
                              {4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
                              {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
                              {20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
                              {1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}};
    int i, j,k;
    int r, l, u, d, dr, ul, dl, ur;
    int vals_max, max;

    max = INT_MIN;

    for(i = 3; i < ROWS - 3; i++){
        for(j = 3; j < COLS - 3; j++){
            vals_max = INT_MIN;

            r = calculateRight(matrix, i, j, 4);
            l = calculateLeft(matrix, i, j, 4);
            u = calculateUp(matrix, i, j, 4);
            d = calculateDown(matrix, i, j, 4);
            dr = calculateDiagonalDR(matrix, i, j, 4);
            ul = calculateDiagonalUL(matrix, i, j, 4);
            dl = calculateDiagonalDL(matrix, i, j, 4);
            ur = calculateDiagonalUR(matrix, i, j, 4);

            int vals[8] = {r, l, u, d, dr, ul, dl, ur};
            for(k = 0; k < 8; k++){
                printf("%d\n", vals[k]);
                if(vals[k] > vals_max)
                    vals_max = vals[k];
            }
            if(vals_max > max)
                max = vals_max;
        }
    }

    printf("Max Product: %d\n", max);

    return 0;

}

int calculateRight(int matrix[ROWS][COLS], int row, int col, int distance){
    int i, j;

    int product = 1;

    for(i = distance-1; i < distance + col; i++){
        product *= matrix[row][i];
    }

    return product;
}

int calculateLeft(int matrix[ROWS][COLS], int row, int col, int distance){
    int i, j;

    int product = 1;

    for(i = col; i > col - distance; i--){
        product *= matrix[row][i];
    }

    return product;
}

int calculateUp(int matrix[ROWS][COLS], int row, int col, int distance){
    int i, j;

    int product = 1;

    for(i = row; i > row - distance; i--){
        product *= matrix[i][col];
    }

    return product;
}

int calculateDown(int matrix[ROWS][COLS], int row, int col, int distance){
    int i, j;

    int product = 1;

    for(i = row; i < row + distance; i++){
        product *= matrix[i][col];
    }

    return product;
}

int calculateDiagonalDR(int matrix[ROWS][COLS], int row, int col, int distance){
    int i, j;

    int product = 1;

    int o_row = row;
    int o_col = col;
    for(; row < o_row + distance && col < o_col + distance; row++, col++){
        product *= matrix[row][col];
    }

    return product;
}

int calculateDiagonalUL(int matrix[ROWS][COLS], int row, int col, int distance){
    int i, j;

    int product = 1;

    int o_row = row;
    int o_col = col;
    for(; row > o_row - distance && col > o_col - distance; row--, col--){
        product *= matrix[row][col];
    }

    return product;
}

int calculateDiagonalDL(int matrix[ROWS][COLS], int row, int col, int distance){
    int i, j;

    int product = 1;

    int o_row = row;
    int o_col = col;
    for(; row < o_row + distance && col > o_col - distance; row++, col--){
        product *= matrix[row][col];
    }

    return product;
}

int calculateDiagonalUR(int matrix[ROWS][COLS], int row, int col, int distance){
    int i, j;

    int product = 1;

    int o_row = row;
    int o_col = col;
    for(; row > o_row - distance && col < o_col + distance; row--, col++){
        product *= matrix[row][col];
    }

    return product;
}
