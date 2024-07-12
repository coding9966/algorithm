class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int len = 0;
        for(int left = 0, right = 0; right < s.length(); right++) {
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left++]);
                //left++;
            }
            st.insert(s[right]);
            len = max(len, right - left + 1);
        }
        return len;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charFreq(128, 0);
        int left = 0, right = 0, maxLen = 0;
        
        while (right < s.length()) {
            if (charFreq[s[right]] > 0) {
                charFreq[s[left]]--;
                left++;
            } else {
                charFreq[s[right]]++;
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
        }
        
        return maxLen;
    }
};
