public class ClientException extends Exception {
    private String message;

    public ClientException(String message) {
        super(message);
        this.message = message;
    }

    public String getMessage() {
        return message;
    }
}

public void findClient(String clientId) throws ClientException {
    Client client = findClientById(clientId);
    if (client == null) {
        throw new ClientException("Client not found: " + clientId);
    }
}