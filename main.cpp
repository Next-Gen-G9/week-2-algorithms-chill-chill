#include <iostream>
#include <vector>
#include <limits>
#include "models/Book.h"
#include "models/User.h"
#include "utils/LibraryUtils.h"

// --- Forward Declarations for Menu Functions ---
void runAdminSession(std::vector<User>& users);
void runUserSession();

// STUDENT TASK: Implement a function that uses a fixed-size array.
// This exercise covers: arrays
void showPromotionalBooks() {
    // 1. Declare a fixed-size array of type 'int' named 'promoIDs'.
    // 2. Initialize it with three hard-coded book IDs, for example: {1, 5, 10}.
    // 3. Print a header, like "--- Today's Featured Books (IDs) ---".
    // 4. Write a loop to iterate through the 'promoIDs' array and print each ID.
}

// --- MAIN APPLICATION (FRAMEWORK) ---

int main() {
    std::vector<User> users = loadUsers();
    while (true) {
        Role userRole = loginUser(users); // Example call
        if (userRole == Role::ADMIN) {
            runAdminSession(users); // Pass users by reference
        } else if (userRole == Role::USER) {
            runUserSession();
        }
    }
    return 0;
}

// Update function signature to accept users by reference
void runAdminSession(std::vector<User>& users) {
    std::vector<Book> libraryBooks = loadBooks();
    bool booksAreSorted = false;
    while(true) {
        // ... Admin menu and switch statement ...
        // Example case:
        // case 1: addBook(libraryBooks); booksAreSorted = false; break;
        // case 7: showPromotionalBooks(); break; // <-- Your new array function
    }
}

void runUserSession() { /* ... Provided ... */ }
// [The full code for main, runAdminSession, etc. would be provided to the student]
// [as it acts as the test harness for their implemented functions.]