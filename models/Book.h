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
    int id;
    string title;
    string author;     
    bool isAvailable;

};

#endif // BOOK_H