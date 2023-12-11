import java.nio.file.attribute.BasicFileAttributes;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.io.IOException;

public class CustomFile {
    private String name;
    private Path path;

    public CustomFile(String name, String path) {
        this.name = name;
        this.path = Paths.get(path);
    }

    public String name() {
        return this.name;
    }

    public BasicFileAttributes readAttributes() {
        try {
            return Files.readAttributes(this.path, BasicFileAttributes.class);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }
}