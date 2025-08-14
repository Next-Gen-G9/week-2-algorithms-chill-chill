#ifndef BOOK_H
#define BOOK_H

#include <string> // Required for std::string
using namespace std;
// STUDENT TASK: Define the structure for a Book.
// This exercise covers: struct, std::string
//
// 1. Define a struct named 'Book'.

// 2. Add the following member variables inside the struct:
//    - an 'int' named 'id'
       int id;
//    - a 'std::string' named 'title'
         string title;
//    - a 'std::string' named 'author'
            string author;
//    - a 'bool' named 'isAvailable'
            bool isAvailable;
//
struct Book {
    // Add member variables here
<<<<<<< HEAD
    
    int id;
    string title;   
    string author;
    bool isAvailable;
    // You can add a constructor if needed
    Book(int bookId, const string& bookTitle, const string& bookAuthor, bool
            available = true)
        : id(bookId), title(bookTitle), author(bookAuthor), isAvailable(available) {}
    // You can also add member functions if needed
    void display() const {
        cout << "ID: " << id << ", Title: " << title
        

=======
   int id;
>>>>>>> c68ab2948f5c18507478ea96fe4260ac131cd8ae
};

#endif // BOOK_H