class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length() < t.length()) return "";

        vector<int> charFreq(128, 0);
        for(auto c : t) {
            charFreq[c]++;
        }

        int left = 0, right = 0, len = INT_MAX, head = 0, counter = t.length();
        while(right < s.length()) {
            if(charFreq[s[right++]]-- > 0) {
                counter--;
            }
            while(counter == 0) {
                if(right - left < len) {
                    head = left;
                    len = right - left;
                }
                if(charFreq[s[left++]]++ >= 0) {
                    counter++;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};