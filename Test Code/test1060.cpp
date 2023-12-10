java
public class Client {
    private boolean isConnected = false;

    public void performAction() {
        if (!isConnected) {
            connect();
        }
        // Perform the specific action after establishing the connection
        if (isConnected) {
            // Perform the action here
            System.out.println("Action performed successfully");
        } else {
            System.out.println("Failed to perform action: Not connected to the server");
        }
    }

    private void connect() {
        int maxAttempts = 3;
        int attempt = 0;
        while (attempt < maxAttempts && !isConnected) {
            try {
                // Attempt to establish the connection
                // Replace the following line with actual connection logic
                // Example: socket = new Socket(serverAddress, port);
                // Example: isConnected = true; (if connection is successful)
                // Simulating connection attempt
                Thread.sleep(1000);
                isConnected = true;  // Simulated successful connection
            } catch (InterruptedException e) {
                System.out.println("Connection attempt interrupted");
            } catch (Exception e) {
                System.out.println("Connection attempt failed: " + e.getMessage());
            }
            attempt++;
        }
        if (!isConnected) {
            System.out.println("Failed to establish connection after " + maxAttempts + " attempts");
        }
    }

    public static void main(String[] args) {
        Client client = new Client();
        client.performAction();
    }
}
