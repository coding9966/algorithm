/*48. Rotate Image
Medium
16.7K
739
Companies

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

void printMatrix(vector<vector<int>> matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
        
    }
}

int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printMatrix(matrix);
    cout << endl;

    Solution().rotate(matrix);
    
    printMatrix(matrix);

    return 0;
}
