#include <stdio.h>

#define N 3 // Assuming a 3x3 matrix

void transpose(int matrix[N][N]) {
    int temp;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    transpose(matrix);

    printf("\nTransposed Matrix:\n");
    printMatrix(matrix);

    return 0;
}
