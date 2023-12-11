public interface DebugContextHolder {
    void setDebugContext(String debugContext);
    String getDebugContext();
}

public class ThreadLocalDebugContextHolder implements DebugContextHolder {
    private static final ThreadLocal<String> debugContext = new ThreadLocal<>();

    @Override
    public void setDebugContext(String context) {
        debugContext.set(context);
    }

    @Override
    public String getDebugContext() {
        return debugContext.get();
    }
}