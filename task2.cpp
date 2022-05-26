#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// class for describing book
class Book {
public:
    // variables for author, name, yearOfPublish, pages of book
    std::string author;
    std::string name;
    std::string yearOfPublish;
    std::string pages;

    // constructor for initializing book
    Book(std::string _author, std::string _name, std::string _yearOfPublish, std::string _pages) {
        this->author = _author;
        this->name = _name;
        this->yearOfPublish = _yearOfPublish;
        this->pages = _pages;
    }
};

// function for printing book
void printBook(Book &book) {
    std::cout << "Author: " << book.author << ", Name: \"" << book.name << "\", Year of publish: " <<
              book.yearOfPublish << ", Pages: " << book.pages << std::endl;
}

// function for printing all books
void printAllBooks(std::vector<Book> &books) {
    for (int i = 0; i < books.size(); i++) {
        printBook(books[i]);
    }
}

// function for parsing book from string read from file
std::vector<std::string> parseBook(std::string bookField) {
    // vector containing info about book
    std::vector<std::string> bookInfo;
    // string that describes splitter between information
    std::string delimiter = ", ";
    // variable declaring starting position in string
    unsigned long long position = 0;
    // iterating through string until position reaches end of string
    // position gets value of index of first delimiter found in string
    while ((position = bookField.find(delimiter)) != std::string::npos) {
        // adding to bookInfo new information between start of string and first found delimiter
        bookInfo.push_back(bookField.substr(0, position));
        // removing already read information
        bookField.erase(0, position + delimiter.length());
    }
    // manually setting position for last delimiter
    position = bookField.find(delimiter);
    // manually adding last component of information
    bookInfo.push_back(bookField.substr(0, position));
    // returning vector with parsed info
    return bookInfo;
}

// function for getting all books from file
std::vector<Book> getBooks(std::string &fileName) {
    // opening file for reading
    std::fstream booksFile("../" + fileName);
    // creating vector for writing books
    std::vector<Book> books;
    // variable for reading info from file
    std::string bookField;
    // reading every string from file
    while (getline(booksFile, bookField)) {
        // parsing string into vector
        std::vector<std::string> bookInfo = parseBook(bookField);
        // adding new book to vector with books by getting info from returned vector
        books.emplace_back(bookInfo.at(0), bookInfo.at(1), bookInfo.at(2), bookInfo.at(3));
        // clearing vector with info about book
        bookInfo.clear();
    }
    // closing file
    booksFile.close();
    // returning all books
    return books;
}

// function for checking if book is already in list
bool
checkBook(std::vector<Book> &books, std::string &bookAuthor, std::string &bookName, std::string &bookYearOfPublish) {
    // iterating through all books
    for (int i = 0; i < books.size(); i++) {
        // if book author, name and yearOfPublish matches new book info, return that book is already in list
        if (books[i].author == bookAuthor && books[i].name == bookName && books[i].yearOfPublish == bookYearOfPublish)
            return true;
    }
    // if equal books not found, return false
    return false;
}

// function for writing book to file
void writeBook(Book &book, std::string &fileName, bool isLast) {
    // opening file for writing
    std::ofstream booksFile;
    booksFile.open("../" + fileName, std::ios_base::app);
    // if book is not last, writing it with moving to new line at end
    if (!isLast)
        booksFile << (book.author + ", " + book.name + ", " + book.yearOfPublish + ", " + book.pages) << std::endl;
        // if book is last writing it without moving to new line
    else
        booksFile << (book.author + ", " + book.name + ", " + book.yearOfPublish + ", " + book.pages);
    // closing file
    booksFile.close();
}

// function for writing books to file
void writeBooks(std::vector<Book> &books, std::string &fileName) {
    // clearing file form previous information
    std::ofstream clearFile("../" + fileName);
    clearFile << "";
    clearFile.close();
    // writing new vector of books to file one by one, if book is last writing it with no new line at end
    for (int i = 0; i < books.size(); i++) {
        if (i != books.size() - 1)
            writeBook(books.at(i), fileName, false);
        else
            writeBook(books.at(i), fileName, true);
    }
}

// function for deleting book
std::vector<Book> deleteBook(std::vector<Book> &books) {
    // ignoring previous input
    std::cin.ignore();
    // variables for book info
    std::string author, name, yearOfPublish;
    // user inputs book info
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);
    std::cout << "Enter book name: ";
    std::getline(std::cin, name);
    std::cout << "Enter book year of publish: ";
    std::cin >> yearOfPublish;
    // iterating through all books
    for (int i = 0; i < books.size(); i++) {
        // if books info matches entered data, deleting book from list
        if (books.at(i).author == author && books.at(i).name == name && books.at(i).yearOfPublish == yearOfPublish) {
            books.erase(books.begin() + i);
        }
    }
    // returning modified list
    return books;
}

// function for adding book
std::vector<Book> addBook(std::vector<Book> &books) {
    // cycle for informing user about duplicate book
    while (true) {
        // variables for book info
        std::string author, name, yearOfPublish, pages;
        // user enters information about new book
        std::cout << "Enter book author: ";
        std::getline(std::cin, author);
        std::cout << "Enter book name: ";
        std::getline(std::cin, name);
        std::cout << "Enter book year of publish: ";
        std::cin >> yearOfPublish;
        std::cout << "Enter book pages count: ";
        std::cin >> pages;
        // checking if book does not exist in list already
        if (checkBook(books, author, name, yearOfPublish)) {
            // asking user to enter info again
            std::cout << "Book is already in library.\nEnter info again" << std::endl;
        } else {
            //if book is not duplicated creating new book with given info
            Book book(author, name, yearOfPublish, pages);
            // adding new book to list
            books.push_back(book);
            // returning modified list
            return books;
        }
    }
}
// function for searching books by author
void searchBooksByAuthor(std::vector<Book> &books) {
    // variable for book author
    std::string author;
    // user enters book author
    std::cout << "Enter author name and surname: ";
    std::getline(std::cin, author);
    // iterating through all books
    for (int i = 0; i < books.size(); i++) {
        // if book author matches input, printing this book
        if (books.at(i).author == author) {
            printBook(books.at(i));
        }
    }
}

// function for searching books by peace of name
void searchBookByName(std::vector<Book> &books) {
    // variable for peace of name
    std::string name;
    // user enters full name or part of it
    std::cout << "Enter book name: ";
    std::getline(std::cin, name);
    // iterating through all books
    for (int i = 0; i < books.size(); i++) {
        // if books name contains entered string, print this book
        if (books.at(i).name.find(name) != std::string::npos) {
            printBook(books.at(i));
        }
    }
}

int main() {
    // file from which we take books
    std::string fileName = "books.txt";
    // getting all books to vector of books
    std::vector<Book> books = getBooks(fileName);

    printAllBooks(books);
    books = addBook(books);
    printAllBooks(books);
    books = deleteBook(books);
    printAllBooks(books);

    searchBooksByAuthor(books);
    searchBookByName(books);
    writeBooks(books, fileName);
    return 0;
}