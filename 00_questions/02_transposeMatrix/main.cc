#include<iostream>
#include<vector>

std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    int raws = matrix.size();
    int columns = matrix[0].size();

    std::vector<std::vector<int>> res(columns, std::vector<int>(raws, 0));
    for(int i = 0; i< raws; i++) {
        for(int j = 0; j < columns; j++) {
            res[j][i] = matrix[i][j];
        }
    }
    return res;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for(auto& raw : matrix) {
        for(auto val : raw) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } 
}
int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8 ,9}
    };

    printMatrix(matrix);
    std::cout << std::endl;
    printMatrix(transposeMatrix(matrix));
    return 0;
}
