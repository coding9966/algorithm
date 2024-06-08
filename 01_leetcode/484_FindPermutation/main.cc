#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size() + 1;
        vector<int> permutation(n);

        // Initialize the minimum lexicographically sorted permutation
        for (int i = 0; i < n; ++i) {
            permutation[i] = i + 1;
        }

        // Traverse the secret signature
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'D') {
                // Find the maximum unused number and fill it into the current position
                int j = i;
                while (j < s.size() && s[j] == 'D') {
                    ++j;
                }
                reverse(permutation.begin() + i, permutation.begin() + j + 1);
                i = j;
            }
        }

        return permutation;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "I";
    vector<int> result1 = solution.findPermutation(s1);
    cout << "Test case 1 result: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    string s2 = "DID";
    vector<int> result2 = solution.findPermutation(s2);
    cout << "Test case 2 result: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}
