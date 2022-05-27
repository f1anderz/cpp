#include <iostream>

// structure for returning array and it`s size from function
struct arrayInfo {
    int *arr;
    int size;
};

// function for filling array
int *fillArray(int size) {
    // declaring array for return
    int *arr = new int[size];
    // user inputs numbers of new array
    std::cout << "Enter array items: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    // returning filled array
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

// function for finding matching elements without duplicates
arrayInfo findMatching(int size1, int *arr1, int size2, int *arr2) {
    // size for new array
    int size = 0;
    // new array for matching elements
    int *arr = new int[size];
    // iterating through first array
    for (int i = 0; i < size1; i++) {
        // iterating through second array
        for (int j = 0; j < size2; j++) {
            // comparing each element of first array with each element of second array
            if (arr1[i] == arr2[j]) {
                // setting flag variable for checking if value is not duplicated
                bool flag = false;
                // iterating through array of matching values
                for(int k = 0; k < size;k++){
                    // if array contains this element, setting flag as true
                    if(arr[k] == arr1[i])
                        flag = true;
                }
                // if element is not duplicated, adding it to end of array and increasing size of array on the same time
                if(!flag)
                    arr[++size - 1] = arr1[i];
            }
        }
    }
    // creating structure for returning and setting it`s values
    arrayInfo arrInf{};
    arrInf.arr = arr;
    arrInf.size = size;
    return arrInf;
}

int main() {
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
    // finding matching elements
    arrayInfo arrInf = findMatching(size1, arr1, size2, arr2);
    // showing matching elements
    printArray(arrInf.arr, arrInf.size);
}
