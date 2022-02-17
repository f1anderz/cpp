#include <iostream>
// including library for strlen() function
#include <cstring>
// including file with numbers
#include "numbers.cpp"

int main() {
    // creating instance of structure Numbers
    struct Numbers numbers;
    // asking user to enter string
    std::cout << "Enter free amount of symbols: ";
    // declaring variable for string
    char input[100];
    // users enters string
    std::cin >> input;
    // declaring variable for sum of ASCII codes
    int asciiSum = 0;
    // iterating through input and adding code values to asciiSum
    for (int i = 0; i < strlen(input); i++) {
        asciiSum += int(input[i]);
    }
    // showing sum of ASCII codes as string
    std::cout << "Sum of ASCII codes: " << asciiSum << std::endl;
    // creating array for all digits of which consists asciiSum number
    int asciiSumNumbers[std::to_string(asciiSum).length()];
    // iterating through all digits in asciiSum and writing it to the array
    for (int i = 0; i < (std::to_string(asciiSum).length() + 2); i++) {
        asciiSumNumbers[i] = asciiSum % 10;
        asciiSum /= 10;
    }

    //      reversing array
    // variable for iterating through new array
    int k = 0;
    // creating new array with size of previous
    int reversedAsciiSumNumbers[sizeof(asciiSumNumbers) / sizeof(*asciiSumNumbers)];
    // reversing array in loop
    for (int i = (sizeof(asciiSumNumbers) / sizeof(*asciiSumNumbers) - 1); i >= 0;) {
        reversedAsciiSumNumbers[k++] = asciiSumNumbers[i--];
    }

    // showing the number, iterating 7 times because of height of each custom digit
    for (int i = 0; i < 7; i++) {
        // iterating through all the digits that exist in number
        for (int j = 0; j < (sizeof(asciiSumNumbers) / sizeof(*asciiSumNumbers)); j++) {
            // setting current number
            int number = asciiSumNumbers[j];
            // searching current number and printing string with current index
            switch (number) {
                case 0:
                    std::cout << '\t' << printZero(numbers, i);
                    break;
                case 1:
                    std::cout << '\t' << printOne(numbers, i);
                    break;
                case 2:
                    std::cout << '\t' << printTwo(numbers, i);
                    break;
                case 3:
                    std::cout << '\t' << printThree(numbers, i);
                    break;
                case 4:
                    std::cout << '\t' << printFour(numbers, i);
                    break;
                case 5:
                    std::cout << '\t' << printFive(numbers, i);
                    break;
                case 6:
                    std::cout << '\t' << printSix(numbers, i);
                    break;
                case 7:
                    std::cout << '\t' << printSeven(numbers, i);
                    break;
                case 8:
                    std::cout << '\t' << printEight(numbers, i);
                    break;
                case 9:
                    std::cout << '\t' << printNine(numbers, i);
                    break;
                default:
                    std::cout << ' ';
                    break;
            }
        }
        // moving to a new line
        std::cout << std::endl;
    }
    return 0;
}
