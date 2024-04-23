#include <iostream>
#include <cstring>

void wrap_text_with_square(const char *text) {
    // Calculate the width of the text
    int width = 0;
    const char *ptr = text;
    while (*ptr != '\0') {
        int line_length = 0;
        
        while (*ptr != '\n' && *ptr != '\0') {
            line_length++;
            ptr++;
        }
        width = std::max(width, line_length);
        if (*ptr == '\n') ptr++;
    }
    
    // Print the top border of the square
    std::cout << "+";
    for (int i = 0; i < width; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
    
    // Iterate through each line and print
    ptr = text;
    while (*ptr != '\0') {
        int index = 0;
        std::cout << "|";
        while (*ptr != '\n' && *ptr != '\0') {
            std::cout << *ptr;
            ptr++;
            index++;
        }
        // Add spaces to make the line the same width
        //for (int i = 0; i < width - (ptr - text); ++i) {
        for (int i = 0; i < width - index; ++i) {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
        if (*ptr == '\n') ptr++;
    }
    
    // Print the bottom border of the square
    std::cout << "+";
    for (int i = 0; i < width; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;
}

int main() {
    const char *text = "AA\nBBB\nCCCCCC";
    wrap_text_with_square(text);
    return 0;
}
