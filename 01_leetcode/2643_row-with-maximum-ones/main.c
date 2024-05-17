#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize){
    int raw = 0, max = 0;
    for(int i = 0; i < matSize; i++) {
        int count = 0;
        for(int j = 0; j < *matColSize; j++) {
            count += (mat[i][j] == 1);
        }
        if(count > max) {
            raw = i;
            max = count;
        }
    }
    
    // Allocate memory for the result array
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = raw;
    res[1] = max;
    
    // Set returnSize to 2
    *returnSize = 2;
    
    return res;
}

int main() {
    int matSize = 2;
    int matColSize = 2;
    int** matrix = (int**)malloc(matSize * sizeof(int*));
    for (int i = 0; i < matSize; i++) {
        matrix[i] = (int*)malloc(matColSize * sizeof(int));
    }

    matrix[0][0] = 0;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 0;

    int returnSize;
    int* result = rowAndMaximumOnes(matrix, matSize, &matColSize, &returnSize);

    printf("Input matrix:\n");
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Output: [%d, %d]\n", result[0], result[1]);

    // Free memory
    for (int i = 0; i < matSize; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(result);

    return 0;
}
