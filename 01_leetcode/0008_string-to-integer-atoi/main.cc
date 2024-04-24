#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        double num = 0;
        int i = 0;
        while(s[i] == ' ') {
            i++;
        }
        bool positive = (s[i] == '+') ? true : false;
        bool negetive = (s[i] == '-') ? true : false;
        if(positive || negetive) {
            i++;
        }

        for(; i < len && (s[i] >= '0' && s[i] <= '9'); i++) {
            num = num*10 + s[i] - '0';
        }
        num = negetive ? -num : num;
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;
        return (int)num;
    }
};

int main() {
    /*Solution sol;
    string s = "   -42";
    int result = sol.myAtoi(s);
    cout << "The result is: " << result << endl;
*/
    Solution sol1;
    string s1 = "words and 987";
    int result1 = sol1.myAtoi(s1);
    cout << "The result1 is: " << result1 << endl;


    return 0;
}