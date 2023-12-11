import java.util.ArrayList;
import java.util.List;

public class Book {
    private String title;
    private String author;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }
}

public class Library {
    private List<Book> books;

    public Library() {
        this.books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public void removeBook(String title) {
        books.removeIf(book -> book.getTitle().equals(title));
    }

    public Book searchByTitle(String title) {
        for (Book book : books) {
            if (book.getTitle().equals(title)) {
                return book;
            }
        }
        return null;
    }

    public void checkOutBook(String title) {
        Book book = searchByTitle(title);
        if (book!= null) {
            // Mark the book as checked out
            System.out.println("Book '" + title + "' has been checked out.");
        } else {
            System.out.println("Book '" + title + "' not found in the library.");
        }
    }

    public void returnBook(String title) {
        Book book = searchByTitle(title);
        if (book!= null) {
            // Mark the book as returned
            System.out.println("Book '" + title + "' has been returned.");
        } else {
            System.out.println("Book '" + title + "' not found in the library.");
        }
    }
}

public class LibraryApp {
    public static void main(String[] args) {
        Library library = new Library();

        Book book1 = new Book("Book1", "Author1");
        Book book2 = new Book("Book2", "Author2");

        library.addBook(book1);
        library.addBook(book2);

        library.checkOutBook("Book1");
        library.returnBook("Book1");

        library.removeBook("Book2");

        Book foundBook = library.searchByTitle("Book1");
        if (foundBook!= null) {
            System.out.println("Found book: " + foundBook.getTitle() + " by " + foundBook.getAuthor());
        } else {
            System.out.println("Book not found.");
        }
    }
}