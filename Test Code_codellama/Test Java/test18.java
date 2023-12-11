import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;

public class IOUtils {
    public static Map<String, Path> getAllFiles(String directoryPath) throws IOException {
        Path directory = Paths.get(directoryPath);
        Map<String, Path> files = new HashMap<>();
        Files.walkFileTree(directory, new SimpleFileVisitor<Path>() {
            @Override
            public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
                files.put(file.getFileName().toString(), file);
                return FileVisitResult.CONTINUE;
            }
        });
        return files;
    }
}