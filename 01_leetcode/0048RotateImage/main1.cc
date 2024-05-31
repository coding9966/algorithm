#include <iostream>
#include <vector>

using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "Original matrix:" << endl;
    for (auto row : matrix) {
        for (auto elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    rotateMatrix(matrix);

    cout << "Rotated matrix:" << endl;
    for (auto row : matrix) {
        for (auto elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}