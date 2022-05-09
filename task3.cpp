#include <iostream>
#include <random>

// function for generating array
int *generateArray(int m) {
    // array for returning
    int *array = new int[m];
    for (int i = 0; i < m; i++) {
        // filling array with numbers from -100 to 100
        array[i] = rand() % 201 + (-100);
    }
    // returning generated array
    return array;
}

// function for showing array
void showArray(int *array, int m) {
    for (int i = 0; i < m; i++)
        // printing element of array with whitespace
        std::cout << array[i] << " ";
    // moving to new line
    std::cout << "\n";
}

// function that merges subArrays of main array
void merge(int *array, int left, int middle, int right) {
    //counting size of first subArray
    int subArrayOne = middle - left + 1;
    //counting size of second subArray
    int subArrayTwo = right - middle;

    // creating temporary subArray 1
    int *leftArray = new int[subArrayOne];
    // creating temporary subArray 2
    int *rightArray = new int[subArrayTwo];

    // writing data to temp subArrays
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[middle + 1 + j];

    // setting start indexes for subArrays and mergedArray
    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // merging two subArrays into one array
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // copying remaining elements of subArray one
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // copying remaining elements of subArray two
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// sort function
int *mergeSort(int *array, int begin, int end) {
    // if no elements left, leaving function
    if (begin >= end)
        return nullptr;

    // declaring variable for middle element
    int mid = begin + (end - begin) / 2;
    // starting recursive sort for first part of array
    mergeSort(array, begin, mid);
    // starting recursive sort for second part of array
    mergeSort(array, mid + 1, end);
    // merging sorted subArrays
    merge(array, begin, mid, end);
    return array;
}

int main() {
    // setting random
    srand(time(nullptr));
    // user enters size of array
    int m;
    std::cout << "Enter m: ";
    std::cin >> m;
    // creating array and generating values in function
    auto array = generateArray(m);
    // showing array
    showArray(array, m);
    // sorting array
    array = mergeSort(array, 0, m - 1);
    // showing array
    showArray(array, m);
    // freeing-up memory allocated for array
    delete[] array;
    return 0;
}