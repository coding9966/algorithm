#include <iostream>

using namespace std;

class Solution {
public:

    void swap(char* a, char* b) {
        char temp = *a;
        *a = *b;
        *b = temp;
    }

    string reverseOnlyLetters(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(!((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= 'a' && s[l] <= 'z'))) {
                l++;
            } else if(!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= 'a' && s[r] <= 'z'))) {
                r--;
            } else {
                swap(&s[l], &s[r]);
                l++;
                r--;
            }
        }
        return s;
    }

    string reverseOnlyLetters1(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!isalpha(s[i])) {
                i++;
            } else if (!isalpha(s[j])) {
                j--;
            } else {
                swap(&s[i++], &s[j--]);
            }
        }
        return s;
    }
};

int main() {
    string s = "a-bC-dEf-ghIj";  //j-Ih-gfE-dCba
    cout << Solution().reverseOnlyLetters(s) << endl;
 
}