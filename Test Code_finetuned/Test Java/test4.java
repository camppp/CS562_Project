import java.io.*;
import java.util.HashMap;

public class ConfigManager {
    private HashMap<String, Serializable> configMap;

    public ConfigManager() {
        this.configMap = new HashMap<>();
    }

    public void setConfig(String key, Serializable value) {
        this.configMap.put(key, value);
    }

    public Serializable getConfig(String key) {
        return this.configMap.get(key);
    }

    public void serializeConfig(String filePath) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filePath))) {
            oos.writeObject(this.configMap);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void deserializeConfig(String filePath) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filePath))) {
            this.configMap = (HashMap<String, Serializable>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}