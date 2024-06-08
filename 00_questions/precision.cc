#include <iostream>
#include <iomanip>

int main() {
      float floatValue = 0.123456789012345678901234567890123456789f;
    double doubleValue = 123456789012.123456789012345678901234567890123456789;

    //double doubleMin = -1.6E+307;

    std::cout << std::setprecision(20) << floatValue << std::endl;     //12 numbers(include ".")
    std::cout << std::setprecision(20) << doubleValue << std::endl;    //18 numbers(include ".")

    return 0;
}
