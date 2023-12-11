public class Result {
    private String message;

    public void setMsg(String message) {
        this.message = message;
    }

    public String getMessage() {
        return message;
    }
}

public class Main {
    public static Result handleCustomError(boolean condition, Result result) {
        if (condition) {
            result.setMsg("Custom error message");
        }
        return result;
    }

    public static void main(String[] args) {
        Result result = new Result();
        result.setMsg("Initial message");
        System.out.println("Before error handling: " + result.getMessage());

        result = handleCustomError(true, result);
        System.out.println("After error handling: " + result.getMessage());

        result = handleCustomError(false, result);
        System.out.println("After error handling: " + result.getMessage());
    }
}