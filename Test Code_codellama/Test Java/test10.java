public class DebugContextHolderExample {
    public static void main(String[] args) {
        // Create a new debugging context
        DebugContext debugContext = new DebugContext();

        // Set the debugging context for the current thread
        DebugContextHolder.setDebugContext(debugContext);

        // Create a new thread
        Thread thread = new Thread(() -> {
            // Get the debugging context for the current thread
            DebugContext context = DebugContextHolder.getDebugContext();

            // Print the debugging context
            System.out.println("Debugging context: " + context);
        });

        // Start the thread
        thread.start();
    }
}