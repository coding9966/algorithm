#include <iostream>

void printPattern(int n) {
    std::cout << n << " ";
    
    // Base case: If n is 0 or negative, return
    if (n <= 0)
        return;
    
    // Recursive call to print the pattern for the reduced value
    printPattern(n - 5);
    
    // Print the value again (except when n is 0, to avoid printing it twice)
    if (n != 0)
        std::cout << n << " ";
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Print the pattern
    printPattern(n);

    return 0;
}
