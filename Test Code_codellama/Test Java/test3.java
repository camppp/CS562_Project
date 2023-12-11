import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.HashMap;

public class ConfigManager {
    private HashMap<String, Serializable> configMap;

    public ConfigManager() {
        configMap = new HashMap<>();
    }

    public void setConfig(String key, Serializable value) {
        configMap.put(key, value);
    }

    public Serializable getConfig(String key) {
        return configMap.get(key);
    }

    public void serializeConfig(String filePath) throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filePath))) {
            oos.writeObject(configMap);
        }
    }
}
