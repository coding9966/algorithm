#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.empty() || p.empty() || s.size() < p.size()) return res;
        
        vector<int> charCount(26, 0); // Frequency array for characters 'a' to 'z'
        
        // Count frequencies of characters in string p
        for (char c : p) {
            charCount[c - 'a']++;
        }
        
        int left = 0, right = 0, count = p.size();
        
        // Initial window setup
        while (right < s.size()) {
            // Expand window by including s[right]
            if (charCount[s[right] - 'a'] > 0) {
                count--; // Decrement count if character in p
            }
            charCount[s[right] - 'a']--; // Decrease count of s[right]
            right++; // Move right pointer
            
            // Found valid anagram
            if (count == 0) {
                res.push_back(left); // Add starting index of anagram
            }
            
            // Shrink window from the left to maintain window size of p
            if (right - left == p.size()) {
                if (charCount[s[left] - 'a'] >= 0) {
                    count++; // Increment count if character in p
                } else {
                    int iiii = 0;
                }
                charCount[s[left] - 'a']++; // Increase count of s[left]
                left++; // Move left pointer to shrink window
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = sol.findAnagrams(s, p);
    
    cout << "Indices of anagrams of \"" << p << "\" in \"" << s << "\": ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.empty() || p.empty() || s.size() < p.size()) return res;

        vector<int> charFreq(128, 0);
        for(auto c : p) {
            charFreq[c]++;
        }

        int left = 0, right = 0, counter = p.size();
        while(right < s.size()) {
            if(charFreq[s[right++]]-- > 0) {
                counter--;
            }
            if(counter == 0) {
                res.push_back(left);
            }
            if(right - left == p.size() && (charFreq[s[left++]]++ >= 0)) {
               counter++;               
            }
        }
        return res;
    }
};
