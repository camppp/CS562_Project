#include <iostream>
#include <string>
#include <vector>

// Book class
class Book {
public:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;

    void checkOut() {
        if (available) {
            available = false;
            std::cout << "Book checked out successfully." << std::endl;
        } else {
            std::cout << "Book is not available for checkout." << std::endl;
        }
    }

    void returnBook() {
        available = true;
        std::cout << "Book returned successfully." << std::endl;
    }
};

// Patron class
class Patron {
public:
    std::string name;
    int ID;
    std::vector<Book> checkedOutBooks;

    void checkOutBook(Book& book) {
        if (book.available) {
            book.checkOut();
            checkedOutBooks.push_back(book);
        } else {
            std::cout << "Book is not available for checkout." << std::endl;
        }
    }

    void returnBook(Book& book) {
        book.returnBook();
        checkedOutBooks.erase(std::remove(checkedOutBooks.begin(), checkedOutBooks.end(), book), checkedOutBooks.end());
    }
};

// Library class
class Library {
public:
    std::vector<Book> books;
    std::vector<Patron> patrons;

    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addPatron(const Patron& patron) {
        patrons.push_back(patron);
    }

    void processCheckout(Patron& patron, Book& book) {
        patron.checkOutBook(book);
    }

    void processReturn(Patron& patron, Book& book) {
        patron.returnBook(book);
    }
};

int main() {
    // Example usage
    Book book1;
    book1.title = "The Catcher in the Rye";
    book1.author = "J.D. Salinger";
    book1.ISBN = "9780316769488";
    book1.available = true;

    Patron patron1;
    patron1.name = "John Doe";
    patron1.ID = 12345;

    Library library;
    library.addBook(book1);
    library.addPatron(patron1);

    library.processCheckout(patron1, book1);
    library.processReturn(patron1, book1);

    return 0;
}
