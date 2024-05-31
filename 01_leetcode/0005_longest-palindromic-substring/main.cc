#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0; // Start index of the longest palindrome found so far
        int maxLength = 1; // Length of the longest palindrome found so far

        for (int i = 0; i < s.size(); ++i) {
            // Find the longest palindrome centered at index i
            int len1 = expandFromCenter(s, i, i); // For odd-length palindromes
            int len2 = expandFromCenter(s, i, i + 1); // For even-length palindromes

            int len = max(len1, len2); // Take the maximum length
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2; // Calculate the start index of the palindrome
            }
        }

        return s.substr(start, maxLength);
    }

private:
    // Function to expand around a center and find the length of the palindrome
    int expandFromCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // After the loop, left and right point to positions beyond the palindrome.
        // So, the length of the palindrome is (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }
};

int main() {
    Solution sol;
    string s = "babad";
    string longest_palindrome = sol.longestPalindrome(s);
    cout << longest_palindrome << endl; // prints "bab"
    return 0;
}