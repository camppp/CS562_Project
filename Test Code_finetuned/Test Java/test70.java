import java.util.regex.Matcher;
import java.util.regex.Pattern;

public int countPackageDeclarations(String sourceCode) {
    Pattern pattern = Pattern.compile("package\\s+[a-zA-Z0-9.]+;");
    Matcher matcher = pattern.matcher(sourceCode);

    int count = 0;
    while (matcher.find()) {
        count++;
    }

    return count;
}