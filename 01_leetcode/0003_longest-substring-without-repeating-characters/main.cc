#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128);
        int left = 0, right = 0, res = 0;
        while(right < s.length()) {
            char r = s[right];
            v[r]++;
            while(v[r] > 1) {
                char l = s[left];
                v[l]--;
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};

int main() {

    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl; //3
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;    //1
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;   //3
    cout << Solution().lengthOfLongestSubstring( "c" )<<endl;        //1
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;         //0

    return 0;
}