#include <stdio.h>
#include <string.h>

void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void transpose_words(char *str) {
    char *word_start = str;
    char *curr = str;

    //for(; *curr != NULL; curr++) {
    while (*curr) {
        curr++;
        if (*curr == '\0') {
            reverse(word_start, curr - 1);
        } else if (*curr == ' ') {
            reverse(word_start, curr - 1);
            word_start = curr + 1;
        }
    }

    reverse(str, curr - 1);
}

int main() {
    char str[] = "I love C++";
    printf("Before: %s\n", str);
    transpose_words(str);
    printf("After: %s\n", str);

    char test_char[] = "abc d kang";
    reverse(test_char, test_char+9);
    printf("%s\n", test_char);

    return 0;
}