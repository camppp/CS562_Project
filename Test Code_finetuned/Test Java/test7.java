public class DataAccessException extends Exception {
    // Constructor that takes a String parameter for the exception message
    public DataAccessException(String msg) {
        // Call the superclass constructor with the provided message
        super(msg);
    }

    // Constructor that takes a Throwable parameter for the exception cause
    public DataAccessException(Throwable cause) {
        // Call the superclass constructor with the provided cause
        super(cause);
    }
}