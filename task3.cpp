#include <iostream>

// function for filling array with values from 1 to 100
int *fillArray(int size) {
    // declaring array for return
    int *arr = new int[size];
    // generating numbers for new array
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
    // returning filled array
    return arr;
}

// bubble sort function
int *bubbleSort(int *arr, int size) {
    // iterating through every element
    for (int i = 0; i < size - 1; i++) {
        // iterating through unsorted elements of array
        for (int j = 0; j < size - i - 1; j++) {
            // if next element is bigger than current, swapping them
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
    // returning sorted array
    return arr;
}

// function for printing array
void printArray(int *arr, int size) {
    // iterating through every element and showing it with whitespace
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    // moving to new line
    std::cout << std::endl;
}

int main() {
    // setting time gap for random
    srand(time(nullptr));
    // variables for size of first and second array
    int size1, size2;
    // user enters size of two arrays
    std::cout << "Enter size of first array: ";
    std::cin >> size1;
    std::cout << "Enter size of second array: ";
    std::cin >> size2;
    // filling both arrays
    int *arr1 = fillArray(size1);
    int *arr2 = fillArray(size2);
    // showing generated arrays
    std::cout << "First array: " << std::endl;
    printArray(arr1, size1);
    std::cout << "Second array: " << std::endl;
    printArray(arr2, size2);
    // counting size for merged array
    int size = size1 + size2;
    // declaring merged array
    int *arr = new int[size];
    // merging arrays
    for (int i = 0; i < size1; i++) {
        arr[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        arr[i + size1] = arr2[i];
    }
    // showing merged array
    std::cout << "Merges array: " << std::endl;
    printArray(arr, size);
    // sorting merged array
    arr = bubbleSort(arr, size);
    // showing sorted merged array
    std::cout << "Sorted array: " << std::endl;
    printArray(arr, size);
}