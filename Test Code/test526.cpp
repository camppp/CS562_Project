java
public class Client {
    private Cache cache;

    public Client(Cache cache) {
        this.cache = cache;
    }

    public String processRequest(String request) {
        if (cache.contains(request)) {
            return cache.get(request);
        } else {
            String result = serverRequest(request);
            cache.put(request, result);
            return result;
        }
    }

    private String serverRequest(String request) {
        // Simulate server request
        return Server.process(request);
    }
}

public class Cache {
    private Map<String, String> data;

    public Cache() {
        this.data = new HashMap<>();
    }

    public boolean contains(String key) {
        return data.containsKey(key);
    }

    public String get(String key) {
        return data.get(key);
    }

    public void put(String key, String value) {
        data.put(key, value);
    }
}

public class Server {
    public static String process(String request) {
        // Simulate server processing
        return "Processed: " + request;
    }
}
