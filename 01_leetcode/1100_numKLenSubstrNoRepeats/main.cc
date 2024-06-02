#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int numKLenSubstrNoRepeats(string S, int K) {
    if (K > S.length()) {
        return 0;
    }

    int count = 0;
    unordered_set<char> window;
    for (int i = 0; i <= S.length() - K; ++i) {
        window.clear();
        bool valid = true;
        for (int j = 0; j < K; ++j) {
            if (window.find(S[i + j]) != window.end()) {
                valid = false;
                break;
            }
            window.insert(S[i + j]);
        }
        if (valid) {
            ++count;
        }
    }

    return count;
}

int main() {
    cout << numKLenSubstrNoRepeats("havefunonleetcode", 5) << endl; // Output: 6
    cout << numKLenSubstrNoRepeats("home", 5) << endl; // Output: 0
    return 0;
}
