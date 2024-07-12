#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n < 3) return n; // If string length is less than 3, the result is the length of the string itself
        
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_map<char, int> charFreq;
        
        while (right < n) {
            charFreq[s[right]]++;
            while (charFreq.size() > 2) {
                charFreq[s[left]]--;
                if (charFreq[s[left]] == 0) {
                    charFreq.erase(s[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "eceba";
    string s2 = "ccaabbb";

    int result1 = sol.lengthOfLongestSubstringTwoDistinct(s1);
    int result2 = sol.lengthOfLongestSubstringTwoDistinct(s2);

    // Output results
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: " << result1 << endl;
    cout << endl;

    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: " << result2 << endl;
    cout << endl;

    return 0;
}
