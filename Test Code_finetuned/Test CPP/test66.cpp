import java.util.Map;

public class Stream {
    private boolean mjpgEnabled;
    private int mjpgStreamPort;
    private int mjpgQuality;
    private int mjpgFps;

    public void configureStream(Map<String, String> settings) {
        String mjpgEnabledStr = settings.get("streams.Mjpg.enabled");
        mjpgEnabled = mjpgEnabledStr.equals("true")? true : false;

        String mjpgStreamPortStr = settings.get("streams.Mjpg.streamPort");
        mjpgStreamPort = Integer.parseInt(mjpgStreamPortStr);

        String mjpgQualityStr = settings.get("streams.Mjpg.quality");
        mjpgQuality = Integer.parseInt(mjpgQualityStr);

        String mjpgFpsStr = settings.get("streams.Mjpg.fps");
        mjpgFps = Integer.parseInt(mjpgFpsStr);

        if (mjpgStreamPort < 0 || mjpgStreamPort > 1023) {
            throw new IllegalArgumentException("Invalid port number. Port number must be between 0 and 1023.");
        }
    }

    // Getters for the stream settings
    public boolean isMjpgEnabled() {
        return mjpgEnabled;
    }

    public int getMjpgStreamPort() {
        return mjpgStreamPort;
    }

    public int getMjpgQuality() {
        return mjpgQuality;
    }

    public int getMjpgFps() {
        return mjpgFps;
    }
}