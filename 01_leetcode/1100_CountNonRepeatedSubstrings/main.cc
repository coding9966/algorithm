/*
1100. Find K-Length Substrings With No Repeated Characters

Given a string S, return the number of substrings of length K with no repeated characters.

Example 1:

Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation: 
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.

Example 2:

Input: S = "home", K = 5
Output: 0
Explanation: 
Notice K can be larger than the length of S. In this case is not possible to find any substring.
*/

#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

int CountNonRepeatedSubstrings(string s, int k) {
    unordered_set<char> window;
    int count = 0;
    for(int i = 0; i <= s.size() - k; i++) {
        window.clear();
        bool valid = true;
        for(int j = 0; j < k; j++) {
            if(window.find(s[i+j]) != window.end()) {
                valid = false;
                break;
            }
            window.insert(s[i+j]);
        }
        if(valid) {
            ++count;
        }     

    }
    return count;
}

int main() {
    string s1 = "havefunonleetcode";
    int k1 = 5;

    cout << "The string " << s1 << " find " << k1 
    << " no repeated substring numbers is " << CountNonRepeatedSubstrings(s1, k1) << endl; 
}