#include <iostream>
#include <cstring>

int main() {
    // asking user to enter string
    std::cout << "Enter free amount of symbols: ";
    // declaring variable for string
    char input[500];
    // user enters string, used cin.getline() method in order to correctly read strings with spaces
    std::cin.getline(input, 500);
    // asking user to enter free number
    std::cout << "Enter any number that is less than amount of symbols you entered: ";
    // creating variable for number
    int n;
    // cycle for making user enter correct number
    while (true) {
        // user enters number
        std::cin >> n;
        // checking if number is less than string size and if it`s bigger than 0
        if (n < strlen(input) && n > 0) {
            // if yes breaking cycle
            break;
        } else {
            // if no asking user to enter number one more time
            std::cout << "Incorrect number. Please enter one more time: ";
        }
    }
    // asking user to enter any symbol
    std::cout << "Enter any symbol: ";
    // declaring variable for symbol
    char symbol;
    // user enters symbol
    std::cin >> symbol;
    // changing n indexed symbol of input to symbol user entered before
    input[n - 1] = symbol;
    // cycle for deleting spaces
    for (int i = 0; i < strlen(input); i++) {
        // checking if current symbol is space
        if (input[i] == ' ') {
            // if yes, from current symbol moving each to place before it
            for (int j = i; j < strlen(input); j++) {
                input[j] = input[j + 1];
            }
        }
    }
    // cycle to change eac symbol that equals to entered from index n to first symbol of string
    for (int i = n; i < strlen(input); i++) {
        // checking if current symbol equals to entered
        if (input[i] == symbol) {
            // if yes changing it to first symbol of string
            input[i] = input[0];
        }
    }
    // showing changed string
    for (int i = 0; i < strlen(input); i++) {
        std::cout << input[i];
    }
    // end of program
    return 0;
}