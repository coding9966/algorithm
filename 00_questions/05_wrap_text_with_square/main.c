/*

Question: Input a string like "AA\nBBB\nCCCCCC", please output it as the format below.

+------+
|AA    |
|BBB   |
|CCCCCC|
+------+

*/


#include <stdio.h>
#include <string.h>

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
        width = (line_length > width) ? line_length : width;
        if (*ptr == '\n') ptr++;
    }

    // Print the square
    printf("+");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("+\n");
    
    ptr = text;
    while (*ptr != '\0') {
        int index = 0;
        printf("|");
        while (*ptr != '\n' && *ptr != '\0') {
            printf("%c", *ptr);
            ptr++;
            index++;
        }
        for (int i = 0; i < width - index; i++) {
            printf(" ");
        }
        printf("|\n");
        if (*ptr == '\n') ptr++;
    }
    
    printf("+");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    const char *text = "AA\nBBB\nCCCCCC";
    wrap_text_with_square(text);
    return 0;
}
