#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int raw = 0, max = 0;
        for(int i = 0; i < mat.size(); i++) {
            int count = 0;
            for(int j = 0; j < mat[0].size(); j++) {
                count += (mat[i][j] == 1);
            }
            if(count > max) {
                raw = i;
                max = count;
            }
        }
        return {raw, max};
    }
};

int main() {
    Solution solution;

    // Test case
    vector<vector<int>> matrix = {{0, 1}, {1, 0}};    //should output [0, 1]
    vector<int> result = solution.rowAndMaximumOnes(matrix);
    cout << "Input matrix:" << endl;
    for (auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
