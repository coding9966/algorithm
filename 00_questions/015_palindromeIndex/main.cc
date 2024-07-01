/*
Given a string of lowercase letters in the range ascii[a-z], determine the index of a character that can be removed to make the string a palindrome. There may be more than one solution, but any will do. If the word is already a palindrome or there is no solution, return -1. Otherwise, return the index of a character to remove.

Example

Query 1: “aaab” Removing ‘b’ at index 3. results in a palindrome, so return 3.

Query 2: “baa” Removing ‘b’ at index 0 results in a palindrome, so return 0.

Query 3: “aaa” : This string is already a palindrome, so return -1. Removing any one of the characters would result in a palindrome, but this test comes first.
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

int palindromeIndex(const string& s) {
    int n = s.length();
    
    if (isPalindrome(s)) {
        return -1;
    }
    
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            // Try removing s[i] and check if the rest is palindrome
            string leftRemoved = s.substr(0, i) + s.substr(i + 1);
            if (isPalindrome(leftRemoved)) {
                return i;
            }
            
            // Try removing s[n - 1 - i] and check if the rest is palindrome
            string rightRemoved = s.substr(0, n - 1 - i) + s.substr(n - i);
            if (isPalindrome(rightRemoved)) {
                return n - 1 - i;
            }
            
            // If neither works, return -1 (though this should not happen based on problem statement)
            return -1;
        }
    }
    
    // Should not reach here based on problem statement constraints
    return -1;
}

int main() {

    string s = "aaab";

    int result = palindromeIndex(s);
    cout << result << endl;
    
    return 0;
}
