java
public class Client {
    private Cache cache;

    public Client(Cache cache) {
        this.cache = cache;
    }

    public String processRequest(String request) {
        String cachedData = getCachedData(request);
        if (!cachedData.isEmpty()) {
            return cachedData;
        } else {
            String result = serverRequest(request);
            putCachedData(request, result);
            return result;
        }
    }

    private String getCachedData(String request) {
        return cache.get(request);
    }

    private void putCachedData(String request, String data) {
        cache.put(request, data);
    }

    private String serverRequest(String request) {
        // Simulate server request
        return Server.process(request);
    }
}
