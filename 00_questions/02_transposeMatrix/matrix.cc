#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

//Transpose the matrix, switch the horizon and vertical
void transposeMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

//Return a transposed matrix, not change the original data.
vector<vector<int>> transposeMatrix1(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int columns = matrix[0].size();
    vector<vector<int>> res(columns, vector<int>(rows, 0));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            res[j][i] = matrix[i][j];
        }
    }
    return res;
}

// Function to flip the matrix and maximize the sum in the top-left quadrant
int flippingMatrix(vector<vector<int>> matrix) {
    int sum = 0;
    int n = matrix.size();
    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < n/2; j++) {
            sum +=
            max(matrix[i][j], 
                max(matrix[i][n-j-1], 
                    max(matrix[n-i-1][j], matrix[n-i-1][n-j-1]))
            );
        }
    }
    return sum;
}

//Sort the matrix in descending order both horizontally and vertically.
void sortMatrix(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size(); // Calculate the size of the submatrix

    // Sort rows in descending order
    for (int i = 0; i < n; ++i) {
        sort(matrix[i].begin(), matrix[i].end(), greater<int>());
    }

   // Sort columns in descending order
    for (int j = 0; j < n; ++j) {
        vector<int> column;
        for (int i = 0; i < n; ++i) {
            column.push_back(matrix[i][j]);
        }
        sort(column.begin(), column.end(), greater<int>());
        for (int i = 0; i < n; ++i) {
            matrix[i][j] = column[i];
        }
    }
}

void printMatrix(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << " " << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "=====================================" << endl;
    cout << "The original matrix is : " << endl;
    printMatrix(matrix);
    cout << "Transposed the matrix is :" << endl;
    transposeMatrix(matrix);
    printMatrix(matrix);

    cout << "=====================================" << endl;


    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "=====================================" << endl;
    cout << "The original matrix1 is : " << endl;
    printMatrix(matrix1);
    cout << "Transposed the matrix is :" << endl;
    transposeMatrix(matrix1);
    printMatrix(matrix1);

    cout << "=====================================" << endl;

    cout << "=====================================" << endl;
    vector<vector<int>> matrix2 = {
            {112, 42, 83, 119},

            {56, 125, 56, 49},

            {15, 78, 101, 43},

            {62, 98, 114, 108}

    }; //414
    printMatrix(matrix2);
    int result = flippingMatrix(matrix2);
    std::cout << "Maximum sum in the top-left quadrant: " << result << std::endl;
    cout << "=====================================" << endl;

    cout << "=====================================" << endl;
    cout << "Sort the matrix" << endl;
    vector<vector<int>> matrix3 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}

    };
    sortMatrix(matrix3);
    printMatrix(matrix3);
    cout << "=====================================" << endl;

    return 0;
}
