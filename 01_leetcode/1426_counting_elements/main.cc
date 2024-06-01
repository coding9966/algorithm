/*
1426. Counting Elements

Given an integer array arr, count how many elements x there are, such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.

Example 1:

Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.

Example 2:

Input: arr = [1,1,3,3,5,5,7,7]
Output: 0
Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.

Example 3:

Input: arr = [1,3,2,3,5,0]
Output: 3
Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.

Example 4:

Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.

Example 5:

Input: arr = [1,1,2]
Output: 2
Explanation: Both 1s are counted because 2 is in the array.
*/

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int CountElements(vector<int> elements) {
            unordered_map<int, int> mp;
            for(auto e : elements) {
                mp[e]++;
            }
            int count = 0;
            for(auto pair : mp) {
                if(mp.count(pair.first + 1)) {
                    count += pair.second;
                }
            }
            return count;
        }
        int CountElements1(vector<int> elements) {
            unordered_set<int> s(elements.begin(), elements.end());
            int count = 0;
            for(auto i : elements) {
                if(s.count(i+1)) {
                    count += 1;
                }
            }
            return count;
        }
};

int main() {
    vector<int> arr1 = {1,2,3};
    cout << "arr1 count : " << Solution().CountElements1(arr1) << endl;

    vector<int> arr2 = {1,1,3,3,5,5,7,7};
    cout << "arr2 count : " << Solution().CountElements1(arr2) << endl;

    vector<int> arr3 = {1,3,2,3,5,0};
    cout << "arr3 count : " << Solution().CountElements(arr3) << endl;    
}
