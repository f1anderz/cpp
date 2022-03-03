#include <iostream>

int main() {
    // declaring variable for input
    char symbol = ' ';
    // declaring variable for size of array
    int size = 0;
    // declaring array for input numbers
    int numbers[size];
    // explaining of what to do next for user
    std::cout << "Enter numbers, when you want to stop enter \"e\"" << std::endl;
    // cycle for entering numbers
    while (true) {
        // creating temporary array and increasing size by 1
        int array[++size];
        // copying our input to temporary array
        for (int i = 0; i < size - 1; i++)
            array[i] = numbers[i];
        // asking user to enter number
        std::cout << "Enter number: ";
        // user enters number
        std::cin >> symbol;
        // checking if symbol is not 'e' end if array has odd number of items
        if (symbol == 'e' && ((size - 1) % 2) == 1) {
            // if symbol is 'e' and array has odd count of items copying temporary array to main array
            for (int i = 0; i < size - 1; i++) {
                numbers[i] = array[i];
            }
            // breaking cycle
            break;
            // if symbol is 'e' but count of items is even, asking user to enter one more number
        } else if (symbol == 'e' && ((size - 1) % 2) == 0) {
            std::cout << "Enter one more number" << std::endl;
            // decreasing size
            size--;
            // id symbol is not 'e' adding new number to temporary array by transforming from ASCII code to number
        } else {
            array[size - 1] = (int) symbol - 48;
            // copying temporary array to main array
            for (int i = 0; i < size; i++) {
                numbers[i] = array[i];
            }
        }
    }
    // showing original list of numbers with space between and breaking line at the end of list
    std::cout << "List of numbers: ";
    for (int i = 0; i < size - 1; i++) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
    // cycle for changing values
    for (int i = 0; i < size - 2; i++) {
        // checking if current number is less than last item
        if (numbers[i] < numbers[size - 2]) {
            // if yes, changing it to middle item
            numbers[i] = numbers[(size - 2) / 2];
        }
    }
    // showing array with changed values with space between
    std::cout << "\nResult: ";
    for (int i = 0; i < size - 1; i++) {
        std::cout << numbers[i] << ' ';
    }
    // ending program
    return 0;
}
