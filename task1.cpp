#include <iostream>

int main() {
    // asking user to enter count of bits he wants to convert
    std::cout << "Enter bit count:  ";
    // declaring variable for bits
    int bit = 0;
    // user enters amount of bits
    std::cin >> bit;
    // declaring variable for bytes and counting them by division bits on 8
    int byte = bit / 8;
    // removing amount of bits that is equal to amount of bytes counted
    bit -= byte * 8;
    // declaring variable for Kilobytes and counting them by division bytes on 1024
    int kByte = byte / 1024;
    // removing amount of bytes that is equal to amount of KB counted
    byte -= kByte * 1024;
    // showing results of program
    std::cout << kByte << " KB " << byte << " bytes " << bit << " bits" << std::endl;
    return 0;
}
