#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size() == 1) return false;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1; i++){ 
            if(nums[i] != i+1)
                return false;
        }
        return nums[nums.size()-1] == nums[nums.size()-2];
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {1, 3, 3, 2};
    vector<int> nums2 = {2, 1, 3};
    vector<int> nums3 = {1, 1};
    vector<int> nums4 = {2, 2};
    cout << sol.isGood(nums1) << endl; // expected output: true
    cout << sol.isGood(nums2) << endl; // expected output: false
    cout << sol.isGood(nums3) << endl; // expected output: true
    cout << sol.isGood(nums4) << endl; // expected output: false
    return 0;
}