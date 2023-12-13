/*209. Minimum Size Subarray Sum
Medium
12K
373
Companies

Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = -1, sum = 0;
        int n = nums.size();
        int res = n + 1;
        while(l < n) {
            if(r+1 < n && sum < target) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }
            if(sum >= target) {
                res = min(res, r-l+1);
            }
        }
        return res == n + 1? 0 : res;
    }
};
