#include <iostream>

int power(int base, int exponent) {
    int result = 1;

    while (exponent > 0) {
        // If the exponent is odd, multiply the base with result
        if (exponent % 2 == 1) {
            result *= base;
        }

        // Now exponent must be even, so divide it by 2
        exponent /= 2;
        
        // Square the base
        base *= base;
    }
    
    return result;
}

int main() {
    int base = 2;
    int exponent = 10;

    std::cout << "Power(" << base << ", " << exponent << ") = " << power(base, exponent) << std::endl;
    return 0;
}
