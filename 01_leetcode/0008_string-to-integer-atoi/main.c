#include <stdio.h>
#include <limits.h>
#include <string.h>

int myAtoi(char* s) {
    int i = 0;
    double result = 0;

    while(s[i] == ' ' && s[i] != '\0') {
        i++;        
    }
    int positive = s[i] == '+' ? 1 : 0;
    int negative = s[i] == '-' ? 1 : 0;
    if(positive == 1 || negative == 1) i++;

    /*for(; s[i] != '\0'; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            int value = s[i] - '0';
            result = result * 10 + value;
        }
    }*/
    for(; i < strlen(s) && s[i] >= '0' && s[i] <= '9'; i++)
    {
        result = result * 10 + s[i] - '0';
    }

    result = negative == 1 ? -result : result;
    result = (result > INT_MAX) ? INT_MAX : result;
    result = (result < INT_MIN) ? INT_MIN : result;

    return (int)result;
}

int main() {
    char* str1 = "42";
    printf("str1: %s ==> : %d\n", str1, myAtoi(str1));

    char* str2 = "   -43";
    printf("str2: %s ==> : %d\n", str2, myAtoi(str2));

    char* str3 = "4193 with words";
    printf("str3: %s ==> : %d\n", str3, myAtoi(str3));

    char* str4 = "words and 987";
    printf("str4: %s ==> : %d\n", str4, myAtoi(str4));
    
}