#include <iostream>

int main() {
    // declaring variable for critical point
    int n;
    // asking user to enter critical point
    std::cout << "Enter critical number: ";
    // user enters critical point
    std::cin >> n;
    // declaring variables for iterating, i => current number, i1 => number before previous, i2 => previous number
    int i = 1, i1 = 1, i2 = 1;
    // showing first two numbers
    std::cout << "\n" << i2 << std::endl;
    // cycle that ends when our number becomes bigger than critical
    do {
        // showing current number
        std::cout << i << std::endl;
        // setting new number by adding (n - 2) and (n - 1) numbers
        i = i1 + i2;
        // moving (n - 1) number to (n - 2) number
        i1 = i2;
        // moving (n) number to (n - 1) number
        i2 = i;
    // ending cycle if our number becomes bigger than critical
    } while (i < n);
    return 0;
}