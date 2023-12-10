class Book {
public:
    string title;
    string author;
    string isbn;
    bool available;

    Book(string title, string author, string isbn) {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
        this->available = true;
    }

    void checkOut() {
        this->available = false;
    }

    void returnBook() {
        this->available = true;
    }
};
