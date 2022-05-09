#include <iostream>

// function for inputting array
int *inputArray(int n) {
    // array for input
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        int num = 0;
        // starting cycle for ensuring correct input number
        while (true) {
            // user enters number
            std::cout << "Enter number 0 or 1: ";
            std::cin >> num;
            // checking if number is 0 or 1
            if (num == 0 || num == 1) {
                // assigning value to array item
                arr[i] = num;
                //leaving cycle
                break;
            } else {
                // number is incorrect, program will ask user to enter same number again
                std::cout << "Incorrect number" << std::endl;
            }
        }
    }
    // returning generated array
    return arr;
}

// function for converting binary number to decimal
int binaryToDecimal(const int *array, int n) {
    int decimal = 0;
    for (int i = 0; i < n; i++) {
        decimal = decimal * 2 + array[i];
    }
    return decimal;
}

// function for converting decimal number to binary
int *decimalToBinary(int number, int n) {
    int *binary = new int[n];
    int i = 0, j, tmp;
    while (number > 0) {
        binary[i] = number % 2;
        number = number / 2;
        i++;
    }
    // reversing array
    for (i = 0, j = n - 1; i < n / 2; i++, j--) {
        tmp = binary[i];
        binary[i] = binary[j];
        binary[j] = tmp;
    }
    return binary;
}

// function for replacing even numbers with 0
int *swapNumbers(int *array, int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            array[i] = 0;
    }
    return array;
}

int main() {
    // user enters size of array
    int n;
    std::cout << "Enter N: ";
    std::cin >> n;
    // creating and filling array
    auto array = inputArray(n);
    // converting array to decimal number
    int number = binaryToDecimal(array, n);
    // checking if number is less than 128
    if (number > 128) {
        // if no converting it back to binary
        array = decimalToBinary(number, n);
        // replacing even numbers with 0
        array = swapNumbers(array, n);
        // converting replaced binary number to decimal
        number = binaryToDecimal(array, n);
    }
    // showing number
    std::cout << number << std::endl;
    // freeing-up memory allocated for array
    delete[] array;
    return 0;
}
