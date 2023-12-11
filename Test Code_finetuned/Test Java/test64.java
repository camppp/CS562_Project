import java.util.ArrayList;
import java.util.List;

class Book {
    private String title;
    private String author;
    private boolean isBorrowed;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.isBorrowed = false;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public boolean isBorrowed() {
        return isBorrowed;
    }

    public void borrow() {
        isBorrowed = true;
    }

    public void returnBook() {
        isBorrowed = false;
    }
}

class Library {
    private List<Book> books;

    public Library() {
        books = new ArrayList<>();
    }

    public void addBook(String title, String author) {
        books.add(new Book(title, author));
    }

    public void borrowBook(String title) {
        Book book = findBook(title);
        if (book!= null &&!book.isBorrowed()) {
            book.borrow();
        } else {
            System.out.println("Book not found or already borrowed.");
        }
    }

    public void returnBook(String title) {
        Book book = findBook(title);
        if (book!= null && book.isBorrowed()) {
            book.returnBook();
        } else {
            System.out.println("Book not found or not borrowed.");
        }
    }

    public void displayAvailableBooks() {
        if (books.isEmpty()) {
            System.out.println("No books available.");
        } else {
            for (Book book : books) {
                if (!book.isBorrowed()) {
                    System.out.println("Title: " + book.getTitle() + ", Author: " + book.getAuthor());
                }
            }
        }
    }

    private Book findBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equals(title)) {
                return book;
            }
        }
        return null;
    }
}