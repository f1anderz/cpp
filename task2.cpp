#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Book {
public:
    std::string author;
    std::string name;
    std::string yearOfPublish;
    std::string pages;

    Book(std::string _author, std::string _name, std::string _yearOfPublish, std::string _pages) {
        this->author = _author;
        this->name = _name;
        this->yearOfPublish = _yearOfPublish;
        this->pages = _pages;
    }
};

void printBook(Book &book) {
    std::cout << "Author: " << book.author << ", Name: \"" << book.name << "\", Year of publish: " <<
              book.yearOfPublish << ", Pages: " << book.pages << std::endl;
}

void printAllBooks(std::vector<Book> &books) {
    for (int i = 0; i < books.size(); i++) {
        printBook(books[i]);
    }
}

std::vector<std::string> parseBook(std::string bookField) {
    std::vector<std::string> bookInfo;
    std::string delimiter = ", ";
    unsigned long long position = 0;
    while ((position = bookField.find(delimiter)) != std::string::npos) {
        bookInfo.push_back(bookField.substr(0, position));
        bookField.erase(0, position + delimiter.length());
    }
    position = bookField.find(delimiter);
    bookInfo.push_back(bookField.substr(0, position));
    return bookInfo;
}

std::vector<Book> getBooks(std::string &fileName) {
    std::fstream booksFile("../" + fileName);
    std::vector<Book> books;
    std::string bookField;
    while (getline(booksFile, bookField)) {
        std::vector<std::string> bookInfo = parseBook(bookField);
        books.emplace_back(bookInfo.at(0), bookInfo.at(1), bookInfo.at(2), bookInfo.at(3));
        bookInfo.clear();
    }
    booksFile.close();
    return books;
}

bool
checkBook(std::vector<Book> &books, std::string &bookAuthor, std::string &bookName, std::string &bookYearOfPublish) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].author == bookAuthor && books[i].name == bookName && books[i].yearOfPublish == bookYearOfPublish)
            return true;
    }
    return false;
}

void writeBook(Book &book, std::string &fileName, bool isLast) {
    std::ofstream booksFile;
    booksFile.open("../" + fileName, std::ios_base::app);
    if (!isLast)
        booksFile << (book.author + ", " + book.name + ", " + book.yearOfPublish + ", " + book.pages) << std::endl;
    else
        booksFile << (book.author + ", " + book.name + ", " + book.yearOfPublish + ", " + book.pages);
    booksFile.close();
}

void writeBooks(std::vector<Book> &books, std::string &fileName) {
    std::ofstream clearFile("../" + fileName);
    clearFile << "";
    clearFile.close();
    for (int i = 0; i < books.size(); i++) {
        if (i != books.size() - 1)
            writeBook(books.at(i), fileName, false);
        else
            writeBook(books.at(i), fileName, true);
    }
}

std::vector<Book> deleteBook(std::vector<Book> &books) {
    std::cin.ignore();
    std::string author, name, yearOfPublish;
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);
    std::cout << "Enter book name: ";
    std::getline(std::cin, name);
    std::cout << "Enter book year of publish: ";
    std::cin >> yearOfPublish;
    for (int i = 0; i < books.size(); i++) {
        if (books.at(i).author == author && books.at(i).name == name && books.at(i).yearOfPublish == yearOfPublish) {
            books.erase(books.begin() + i);
        }
    }
    return books;
}

std::vector<Book> addBook(std::vector<Book> &books) {
    while (true) {
        std::string author, name, yearOfPublish, pages;
        std::cout << "Enter book author: ";
        std::getline(std::cin, author);
        std::cout << "Enter book name: ";
        std::getline(std::cin, name);
        std::cout << "Enter book year of publish: ";
        std::cin >> yearOfPublish;
        std::cout << "Enter book pages count: ";
        std::cin >> pages;
        if (checkBook(books, author, name, yearOfPublish)) {
            std::cout << "Book is already in library.\nEnter info again" << std::endl;
        } else {
            Book book(author, name, yearOfPublish, pages);
            books.push_back(book);
            return books;
        }
    }
}

void searchBooksByAuthor(std::vector<Book> &books) {
    std::string author;
    std::cout << "Enter author name and surname: ";
    std::getline(std::cin, author);
    for (int i = 0; i < books.size(); i++) {
        if (books.at(i).author == author) {
            printBook(books.at(i));
        }
    }
}

void searchBookByName(std::vector<Book> &books) {
    std::string name;
    std::cout << "Enter book name: ";
    std::getline(std::cin, name);
    for (int i = 0; i < books.size(); i++) {
        if (books.at(i).name.find(name) != std::string::npos) {
            printBook(books.at(i));
        }
    }
}

int main() {
    std::string fileName = "books.txt";
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