/*
1087. Brace Expansion

A string S represents a list of words.

Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].

For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].

Return all words that can be formed in this manner, in lexicographical order.

Example 1:

Input: "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]

Example 2:

Input: "abcd"
Output: ["abcd"]
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> expand(string S) {
        vector<string> result;
        dfs(S, 0, "", result);
        sort(result.begin(), result.end());
        return result;
    }

private:
    void dfs(const string& S, int index, string current, vector<string>& result) {
        if (index == S.length()) {
            result.push_back(current);
            return;
        }
        
        if (S[index] == '{') {
            int end = index + 1;
            while (S[end] != '}') ++end;
            string options = S.substr(index + 1, end - index - 1);
            index = end + 1;
            vector<string> choices;
            int start = 0;
            while (start < options.length()) {
                int comma = options.find(',', start);
                if (comma == string::npos) comma = options.length();
                choices.push_back(options.substr(start, comma - start));
                start = comma + 1;
            }
            sort(choices.begin(), choices.end());
            for (const string& choice : choices) {
                dfs(S, index, current + choice, result);
            }
        } else {
            dfs(S, index + 1, current + S[index], result);
        }
    }
};

int main() {
    Solution solution;
    // Test example 1
    string input1 = "{a,b}c{d,e}f";
    vector<string> output1 = solution.expand(input1);
    cout << "Example 1 Output:" << endl;
    for (const string& str : output1) {
        cout << str << " ";
    }
    cout << endl;

    // Test example 2
    string input2 = "abcd";
    vector<string> output2 = solution.expand(input2);
    cout << "Example 2 Output:" << endl;
    for (const string& str : output2) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
