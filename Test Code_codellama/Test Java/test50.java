import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.attribute.BasicFileAttributes;
import java.nio.file.attribute.FileTime;

public class CustomFile {
    private final Path path;

    public CustomFile(Path path) {
        this.path = path;
    }

    public String name() {
        return path.getFileName().toString();
    }

    public BasicFileAttributes readAttributes() throws IOException {
        BasicFileAttributes attributes = Files.readAttributes(path, BasicFileAttributes.class);
        return attributes;
    }
}