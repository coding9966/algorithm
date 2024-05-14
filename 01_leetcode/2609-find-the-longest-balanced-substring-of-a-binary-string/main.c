#include <stdio.h>
#include <string.h>
#include <math.h>

int findTheLongestBalancedSubstring(char * s) {
    int res = 0;          // Initialize the result variable to store the length of the longest balanced substring.
    int count[2] = {0};   // Initialize an array to count the number of consecutive '0's and '1's encountered.
    
    for (int i = 0; s[i] != '\0'; i++) {  // Loop through the characters of the string until the end ('\0') is reached.
        if (s[i] == '1') {                // If the current character is '1':
            count[1]++;                   // Increment the count of '1's.
            res = fmax(res, 2 * fmin(count[0], count[1]));  // Update the result with the maximum length of balanced substring so far.
        } else if (i == 0 || s[i - 1] == '1') {  // If the current character is '0' and it's the first character or the previous character was '1':
            count[0] = 1;                         // Reset the count of '0's to 1.
            count[1] = 0;                         // Reset the count of '1's to 0.
        } else {  // If the current character is '0' and the previous character was also '0':
            count[0]++;  // Increment the count of '0's.
        }
    }
    return res;    // Return the length of the longest balanced substring.
}

int main() {
    char s[] = "00111";
    printf("%d\n", findTheLongestBalancedSubstring(s));
    return 0;
}
