#include<iostream>
#include<stack>

class Solution{
    public:
        bool isValid(const std::string str) {
            std::stack<char> s;
            for(int i = 0; i < str.size(); i++) {
                if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
                    s.push(str[i]);
                } else {
                    if(s.size() == 0)
                        return false;

                    char match;
                    char c = s.top();
                    s.pop();
                    if(c == '(') {
                        match = ')';
                    } else if (c == '{') {
                        match = '}';
                    } else if (c == '[') {
                        match = ']';
                    }

                    if(str[i] != match)
                        return false;

                }
            }
            if(!s.empty())
                return false;

            return true;
        }

};


int main() {
    std::string str = ")";
    std::cout << Solution().isValid(str) << std::endl;
    return 0;
}
