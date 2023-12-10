java
import java.util.List;
import java.util.Locale;

public class FileFilter {
    public boolean isFileAcceptable(String fileName, List<String> fileFilters) {
        if (fileFilters.isEmpty()) {
            return true; // No filters provided, all files are acceptable
        }

        String fileSuffix = fileName.substring(fileName.lastIndexOf('.') + 1).toLowerCase(Locale.ROOT);
        for (String filter : fileFilters) {
            if (fileSuffix.equals(filter.toLowerCase(Locale.ROOT))) {
                return true; // File suffix matches one of the filters
            }
        }
        return false; // File suffix does not match any of the filters
    }
}
