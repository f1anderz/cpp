#include <iostream>

// structure for writing current max sum and array of it`s origin
struct CurrentMax {
    int arr[2][2];
    int sum;
};

int main() {
    // setting time gap for random
    srand(time(nullptr));
    // size for 2d array
    int sizeX, sizeY;
    // user enters size until it is more than 2x2
    while (true) {
        std::cout << "Enter X size: ";
        std::cin >> sizeX;
        std::cout << "Enter Y size: ";
        std::cin >> sizeY;
        if (sizeX > 2 && sizeY > 2) {
            break;
        }
        std::cout << "Enter size again. It must be more than 2x2" << std::endl;
    }
    // creating array and filling it with values from -100 to 100
    int arr[sizeY][sizeX];
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            arr[i][j] = rand() % 200 + (-100);
        }
    }
    // showing array
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    // creating structure with very small sum element, for comparing
    CurrentMax currentMax;
    currentMax.sum = -5000;
    // iterating through every element of array except last ones, because we count it by i+1 and j+1
    for (int i = 0; i < sizeY - 1; i++) {
        for (int j = 0; j < sizeX - 1; j++) {
            // counting sum by multiplying diagonal elements
            int sum = arr[i][j] * arr[i + 1][j + 1] + arr[i + 1][j] * arr[i][j + 1];
            // if new sum is bigger than previous, rewrite structure
            if (sum > currentMax.sum) {
                currentMax.sum = sum;
                currentMax.arr[0][0] = arr[i][j];
                currentMax.arr[1][0] = arr[i + 1][j];
                currentMax.arr[0][1] = arr[i][j + 1];
                currentMax.arr[1][1] = arr[i + 1][j + 1];
            }
        }
    }
    // showing Max sum of multiplication diagonal elements and these elements
    std::cout << "Max sum: " << currentMax.sum << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << currentMax.arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}