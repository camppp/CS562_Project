#include <string>
#include <vector>

class BookCollection {
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                break;
            }
        }
    }

    int getTotalPages() const {
        int totalPages = 0;
        for (const auto& book : books) {
            totalPages += book.getPageCount();
        }
        return totalPages;
    }

    std::string getBookInfo(const std::string& title) const {
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                return book.getAuthor() + " - " + std::to_string(book.getPageCount());
            }
        }
        return "Book not found";
    }

private:
    std::vector<Book> books;
};
