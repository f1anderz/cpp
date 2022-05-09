#include <iostream>

// function for inputting values of array
int **fillArray(int m, int n) {
    // initializing 2d array for input
    int **arr = new int *[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }
    // filling array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // user enters value for given row and column
            int inp;
            std::cout << "Enter number of row " << i + 1 << ", column " << j + 1 << ": ";
            std::cin >> inp;
            arr[i][j] = inp;
        }
    }
    // returning array
    return arr;
}

// function for printing array
void showArray(int **array, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // showing element and whitespace
            std::cout << array[i][j] << '\t';
        }
        // moving to new line
        std::cout << '\n';
    }
    // showing splitter for better view
    std::cout << "--------------------------" << std::endl;
}

// function for swapping rows which contain max and min elements
int **swapRows(int **array, int m, int n) {
    // variables for max and min element and their rows
    int max = array[0][0], min = array[0][0], maxRow = 0, minRow = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // assigning max and maxRow value if element is bigger than current max element
            if (array[i][j] > max) {
                max = array[i][j];
                maxRow = i;
            }
            // assigning min and minRow value if element is less than current min element
            if (array[i][j] < min) {
                min = array[i][j];
                minRow = i;
            }
        }
    }
    // swapping rows containing min and max elements
    for (int i = 0; i < n; i++)
        std::swap(array[minRow][i], array[maxRow][i]);
    // returning array
    return array;
}

// function for swapping columns which contain max and min elements
int **swapColumns(int **array, int m, int n) {
    // variables for max and min element and their columns
    int max = array[0][0], min = array[0][0], maxColumn = 0, minColumn = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // assigning max and maxColumn value if element is bigger than current max element
            if (array[i][j] > max) {
                max = array[i][j];
                maxColumn = j;
            }
            // assigning min and minColumn value if element is less than current min element
            if (array[i][j] < min) {
                min = array[i][j];
                minColumn = j;
            }
        }
    }
    // swapping columns containing min and max elements
    for (int i = 0; i < m; i++)
        std::swap(array[i][minColumn], array[i][maxColumn]);
    // returning array
    return array;
}

int main() {
    // user enters size of 2D array
    int m, n;
    std::cout << "Enter m: ";
    std::cin >> m;
    std::cout << "Enter n: ";
    std::cin >> n;
    // creating and filling array
    int **array = fillArray(m, n);
    // showing array before swaps
    std::cout << "Array before swaps: " << std::endl;
    showArray(array, m, n);
    // showing array after swapping rows
    std::cout << "Array after row swap: " << std::endl;
    swapRows(array, m, n);
    showArray(array, m, n);
    // showing array after swapping rows and columns
    std::cout << "Array after row and column swap: " << std::endl;
    swapColumns(array, m, n);
    showArray(array, m, n);
    // freeing-up memory allocated for array
    delete[] array;
    return 0;
}