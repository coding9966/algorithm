#include<iostream>
#include<stack>

std::string transposeWord(const std::string& str) {
    std::stack<std::string> s;
    std::string word = "";
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            s.push(word);
            word = "";
        } else {
            word += str[i];
        }
    }
    s.push(word);
    std::string res;
    while(!s.empty()) {
        res += s.top();
        res += " ";
        s.pop();
    }
    return res;
}

int main() {
    std::string str = "I love C++";
    std::cout << transposeWord(str) << std::endl;
    return 0;
}
