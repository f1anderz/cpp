#include <iostream>

int main() {
#pragma region First equation
    // declaring variables for first equation
    double a1, b1, c1;
    // start of cycle for 0 coefficient check
    do {
        //asking user to enter all coefficients
        std::cout << " Enter coefficients for first equation:" << std::endl;
        // asking user to enter coefficient a
        std::cout << "  a: ";
        // user enters coefficient a
        std::cin >> a1;
        // asking user to enter coefficient b
        std::cout << " b: ";
        // user enters coefficient b
        std::cin >> b1;
        // asking user to enter coefficient c
        std::cout << " c: ";
        // user enters coefficient c
        std::cin >> c1;
    // while statement checks if none of the entered coefficients is 0
    } while (a1 == 0 || b1 == 0 || c1 == 0);
#pragma endregion First equation
#pragma region Second equation
    // declaring variables for second equation
    double a2, b2, c2;
    // start of cycle for 0 coefficient check
    do {
        //asking user to enter all coefficients
        std::cout << "Enter coefficients for second equation:" << std::endl;
        // asking user to enter coefficient a
        std::cout << "  a: ";
        // user enters coefficient a
        std::cin >> a2;
        // asking user to enter coefficient b
        std::cout << " b: ";
        // user enters coefficient b
        std::cin >> b2;
        // asking user to enter coefficient c
        std::cout << " c: ";
        // user enters coefficient c
        std::cin >> c2;
    // while statement checks if none of the entered coefficients is 0
    } while (a2 == 0 || b2 == 0 || c2 == 0);
#pragma endregion Second equation
    // checking if coefficients are proportional
    if (a1 / a2 == b1 / b2) {
        // if all are proportional lines are equal
        if (c1 / c2 == a1 / a2) {
            // showing result of the program
            std::cout << "Lines are equal" << std::endl;
        // if only A and B are proportional, lines are parallel
        } else {
            // showing result of the program
            std::cout << "Lines are parallel" << std::endl;
        }
    // if sum of multiplicated coefficients A and B equals to 0, lines are perpendicular
    } else if (a1 * a2 + b1 * b2 == 0) {
        // showing result of the program
        std::cout << "Lines are perpendicular" << std::endl;
    // if none of the conditions are true, then lines are crossing
    } else {
        // showing result of the program
        std::cout << "Lines are crossing" << std::endl;
    }
    return 0;
}