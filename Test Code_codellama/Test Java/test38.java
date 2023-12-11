import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.util.HashMap;
import java.util.Map;

public class MockConnectionBaseUrlFetcher {
    private Map<String, URLConnection> connections = new HashMap<>();

    public InputStream getUncachedInputStream(String url) throws IOException {
        URLConnection connection = new URL(url).openConnection();
        connections.put(url, connection);
        return connection.getInputStream();
    }

    public void addConnection(String url, URLConnection connection) {
        connections.put(url, connection);
    }

    public void close() throws IOException {
        for (URLConnection connection : connections.values()) {
            connection.close();
        }
    }
}