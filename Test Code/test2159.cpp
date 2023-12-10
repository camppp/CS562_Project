java
// Define the ConnectionResult class
public class ConnectionResult {
    // Define the result types as constants
    public static final String ASSOCIATION_REJECTED = "AssociationRejected";
    public static final String CONNECTION_FAILED = "ConnectionFailed";
    public static final String CONNECTION_ESTABLISHED = "ConnectionEstablished";

    // Private constructor to enforce required parameters
    private ConnectionResult(String resultType, String requiredParam1, String requiredParam2) {
        // Implementation specific to each result type
        // For example, 'AssociationRejected' may require two specific parameters
        // while 'ConnectionFailed' may require only one parameter
        // and 'ConnectionEstablished' may not require any parameters
    }

    // Factory methods to create instances with required parameters
    public static ConnectionResult createAssociationRejected(String requiredParam1, String requiredParam2) {
        return new ConnectionResult(ASSOCIATION_REJECTED, requiredParam1, requiredParam2);
    }

    public static ConnectionResult createConnectionFailed(String requiredParam) {
        return new ConnectionResult(CONNECTION_FAILED, requiredParam, null);
    }

    public static ConnectionResult createConnectionEstablished() {
        return new ConnectionResult(CONNECTION_ESTABLISHED, null, null);
    }

    // Example usage
    public static void main(String[] args) {
        // Attempting to create an instance without required parameters will result in a compile-time error
        // ConnectionResult invalidResult = new ConnectionResult(ASSOCIATION_REJECTED, null, null); // Compile-time error
        ConnectionResult validResult = ConnectionResult.createAssociationRejected("param1", "param2");
    }
}
