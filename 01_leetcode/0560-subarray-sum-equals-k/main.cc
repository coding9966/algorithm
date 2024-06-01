#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sumFreq; // Store the cumulative sum frequencies
    int count = 0;
    int currSum = 0;

    sumFreq[0] = 1; // Initialize with 0 sum frequency
    
    for (int num : nums) {
        currSum += num;
        count += sumFreq[currSum - k]; // Check if there exists a sum that equals k
        sumFreq[currSum]++;
    }
    
    return count;
}

int subarraySum1(vector<int>& nums, int k) {
        int ans = 0, s = 0;
        unordered_map<int, int> cnt{{0, 1}}; 

        for (int x : nums) {
            s += x;
            ans += cnt.count(s - k) ? cnt[s - k] : 0;
            cnt[s]++;
        }

        return ans;

    }
int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << subarraySum1(nums, k) << endl; // Output: 2

    return 0;
}
