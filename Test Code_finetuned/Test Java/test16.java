import java.io.IOException;
import java.nio.file.*;
import java.util.HashMap;
import java.util.Map;

public class IOUtils {
    public static Map<String, Path> getAllFiles(String directoryPath) throws IOException {
        Map<String, Path> allFiles = new HashMap<>();
        Files.walk(Paths.get(directoryPath))
               .filter(Files::isRegularFile)
               .forEach(path -> allFiles.put(directoryPath.substring(directoryPath.length() + 1) + path.getFileName().toString(), path));
        return allFiles;
    }
}