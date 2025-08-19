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
    int promoIDs[3] = {1, 5, 10};
    std::cout << "--- Today's Featured Books (IDs) ---" << std::endl;
    for (int id : promoIDs) {
        std::cout << "Book ID: " << id << std::endl;
    }
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
        // Display admin menu options
        std::cout << "Admin Menu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Remove Book\n";    
        std::cout << "3. Check Out Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Sort Books by Title\n";
        std::cout << "6. Show All Books\n";
        std::cout << "7. Show Promotional Books\n"; // <-- Your new array function
        std::cout << "8. Exit\n";
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue; // Restart the loop
        }
        if (choice < 1 || choice > 8) {
            std::cout << "Invalid choice. Please try again." << std::endl;
            continue; // Restart the loop
        }
        switch (choice) {
            case 1: addBook(libraryBooks); booksAreSorted = false; break;
            case 2: removeBook(libraryBooks); break; // Implement this function
            case 3: checkOutBook(libraryBooks); break; // Implement this function
            case 4: returnBook(libraryBooks); break; // Implement this function
            case 5: sortBooksByTitle(libraryBooks); booksAreSorted = true; break;
            case 6: showAllBooks(libraryBooks, booksAreSorted); break; // Implement this function
            case 7: showPromotionalBooks(); break; // <-- Call your new array function
            case 8: return; // Exit the admin session
            default: std::cout << "Invalid choice. Please try again." << std::endl; break;
        }
        // Save the books after any modification
        saveBooks(libraryBooks);
        // Optionally, you can also save users if needed
        saveUsers(users); // Assuming you have a function to save users
        // Optionally, you can also show the promotional books after each operation
        showPromotionalBooks(); // Call your new array function
        // Optionally, you can also show the updated list of books
        std::cout << "--- Updated Book List ---" << std::endl;
        for (const auto& book : libraryBooks) {
            std::cout << "ID: " << book.id << ", Title: " << book.title << std::endl;
        }
    }
}

void runUserSession() { /* ... Provided ... */ }
// [The full code for main, runAdminSession, etc. would be provided to the student]
// [as it acts as the test harness for their implemented functions.]