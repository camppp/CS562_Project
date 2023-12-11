public class DataAccessException extends Exception {
    public DataAccessException(String msg) {
        super(msg);
    }

    public DataAccessException(Throwable cause) {
        super(cause);
    }
}