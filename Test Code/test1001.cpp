java
public class LoggerConfig {
    private String ini;
    private String loggerType;
    private int verbosity;
    private String filePath;

    public LoggerConfig(String ini, String loggerType, int verbosity, String filePath) {
        this.ini = ini;
        this.loggerType = loggerType;
        this.verbosity = verbosity;
        this.filePath = filePath;
    }

    // Getters and setters can be added if required
}
