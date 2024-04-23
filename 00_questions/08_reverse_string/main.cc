#include <iostream>
#include <cstring>

void reverse_string(char *str) {
    int length =  std::strlen(str);
    char* start = str;
    char* end = str + length - 1;
    while(start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}

int main() {
    char str[] = "abcd";
    std::cout << "Original string: " << str << std::endl;
    
    reverse_string(str);
    
    std::cout << "Reversed string: " << str << std::endl;
    
    return 0;
}
