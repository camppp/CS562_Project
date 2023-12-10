#include <string>
#include <vector>
#include <algorithm>

class Book {
public:
    Book(const std::string& title, const std::string& author, int pageCount)
        : m_title(title), m_author(author), m_pageCount(pageCount) {}

    std::string getTitle() const { return m_title; }
    std::string getAuthor() const { return m_author; }
    int getPageCount() const { return m_pageCount; }

private:
    std::string m_title;
    std::string m_author;
    int m_pageCount;
};

class BookCollection {
public:
    void addBook(const Book& book) {
        m_books.push_back(book);
    }

    void removeBook(const std::string& title) {
        m_books.erase(std::remove_if(m_books.begin(), m_books.end(),
            [title](const Book& book) { return book.getTitle() == title; }), m_books.end());
    }

    int getTotalPages() const {
        int total = 0;
        for (const auto& book : m_books) {
            total += book.getPageCount();
        }
        return total;
    }

    std::string getBookInfo(const std::string& title) const {
        for (const auto& book : m_books) {
            if (book.getTitle() == title) {
                return "Author: " + book.getAuthor() + ", Page Count: " + std::to_string(book.getPageCount());
            }
        }
        return "Book not found";
    }

private:
    std::vector<Book> m_books;
};
