#include <iostream>
#include <fstream>
#include <string>

// function for replacing words
std::string replaceFirstAndLast(const std::string& str){
    // string for returning result
    std::string result;
    // variable for declaring start of first word
    int firstWordStart = 0;
    // variable for declaring first word end
    int firstWordEnd  = str.find(' ');

    // variable for declaring start of last word
    int lastWordStart = str.find_last_of(' ') + 1;
    // variable for declaring last word end
    int lastWordEnd = str.size() - lastWordStart;
    // variable for declaring start of string between first and last word
    int restOfStringStart = firstWordEnd;
    // variable for declaring end of string between first and last word
    int restOfStringEnd = lastWordStart - firstWordEnd;
    // writing to string 'last word + rest of string + first word' by cutting main string onto pieces with substr()
    result = str.substr(lastWordStart, lastWordEnd)
               + str.substr(restOfStringStart, restOfStringEnd)
               + str.substr(firstWordStart, firstWordEnd);
    // returning string with replaced first and last word
    return result;
}

int main() {
    // variable for reading text from file
    std::string fileText;
    // file where we take text
    std::ifstream fileToRead("../file1.txt");
    // file where we write new text
    std::ofstream fileToWrite("../file2.txt");
    // reading every string of file fileToRead to variable FileText
    while (getline(fileToRead, fileText)) {
        // assigning new value to fileText with already replaced first and last words
        fileText = replaceFirstAndLast(fileText);
        // writing replaced string to file
        fileToWrite << fileText << '\n';
    }
    // closing both files
    fileToRead.close();
    fileToWrite.close();
    // opening two files for showing text
    std::ifstream file1("../file1.txt");
    std::ifstream file2("../file2.txt");
    // showing file1.txt by reading every string of it using getline()
    std::cout << "file1.txt" << std::endl;
    while (getline(file1, fileText)) {
        std::cout << fileText << std::endl;
    }
    // showing file2.txt by reading every string of it using getline()
    std::cout << "file2.txt" << std::endl;
    while (getline(file2, fileText)) {
        std::cout << fileText << std::endl;
    }
    // closing both files
    file1.close();
    file2.close();
    return 0;
}