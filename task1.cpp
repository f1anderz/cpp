#include <iostream>
#include <fstream>
#include <string>

std::string replaceFirstAndLast(const std::string& str){
    std::string result;
    int firstWordStart = 0;
    int firstWordEnd  = str.find(' ');

    int lastWordStart = str.find_last_of(' ') + 1;
    int lastWordEnd = str.size() - lastWordStart;

    int restOfStringStart = firstWordEnd;
    int restOfStringEnd = lastWordStart - firstWordEnd;

    result = str.substr(lastWordStart, lastWordEnd)
               + str.substr(restOfStringStart, restOfStringEnd)
               + str.substr(firstWordStart, firstWordEnd);

    return result;
}

int main() {
    std::string fileText;
    std::ifstream fileToRead("../file1.txt");
    std::ofstream fileToWrite("../file2.txt");
    while (getline(fileToRead, fileText)) {
        std::string firstWord = fileText.substr(0,fileText.find(' '));
        std::string lastWord = fileText.substr(fileText.find_last_of(' ') + 1, fileText.length());
        fileText = replaceFirstAndLast(fileText);
        fileToWrite << fileText << '\n';
    }
    fileToWrite.close();
    fileToRead.close();
    return 0;
}