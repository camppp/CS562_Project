public class Library {
    private List<Book> books;

    public Library() {
        books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public void removeBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equals(title)) {
                books.remove(book);
                break;
            }
        }
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
        if (book != null) {
            book.setCheckedOut(true);
        }
    }

