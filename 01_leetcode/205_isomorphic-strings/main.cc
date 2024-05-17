#include <iostream>
#include <unordered_map> 

using namespace std; 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> dic1;
        unordered_map<char, char> dic2;
        for(int i = 0; i<s.length(); i++){
            if((dic1.count(s[i]) || dic2.count(t[i])) && (dic1[s[i]] != t[i] || dic2[t[i]] != s[i])){
                return false;
            } else {
                dic1[s[i]] = t[i];
                dic2[t[i]] = s[i]; 
            }
        }
        return true;
    }
};

class Solution1 {
public:
    // time/space: O(n)/O(1)
    bool isIsomorphic(string s, string t) {
        // map `s` to `i` and `t` to `j`
        unordered_map<char, int> s2i, t2j;
        for (auto& c : s) {
            if (s2i.count(c) != 0) continue;
            s2i[c] = s2i.size();
        }
        for (auto& c : t) {
            if (t2j.count(c) != 0) continue;
            t2j[c] = t2j.size();
        }

        // compare `s` and `t` after mapping
        for (int i = 0; i < s.size(); i++) {
            if (s2i[s[i]] != t2j[t[i]]) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    std::string s1 = "egg";
    std::string t1 = "add";
    std::cout << "Isomorphic? " << solution.isIsomorphic(s1, t1) << std::endl;

    std::string s2 = "foo";
    std::string t2 = "bar";
    std::cout << "Isomorphic? " << solution.isIsomorphic(s2, t2) << std::endl;

    std::string s3 = "paper";
    std::string t3 = "title";
    std::cout << "Isomorphic? " << solution.isIsomorphic(s3, t3) << std::endl;

    return 0;
}