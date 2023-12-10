java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LicenseCommentCounter {
    public static int countLicenseComments(String filePath) {
        int count = 0;
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            boolean inMultiLineComment = false;
            Pattern pattern = Pattern.compile("(?i)\\bLicense\\b");
            while ((line = reader.readLine()) != null) {
                if (inMultiLineComment) {
                    if (line.contains("*/")) {
                        inMultiLineComment = false;
                    }
                } else {
                    if (line.contains("/*") || line.contains("/**")) {
                        inMultiLineComment = true;
                    } else if (line.contains("//")) {
                        Matcher matcher = pattern.matcher(line);
                        if (matcher.find()) {
                            count++;
                        }
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return count;
    }

    public static void main(String[] args) {
        String filePath = "path_to_source_code_file";
        int licenseCommentCount = countLicenseComments(filePath);
        System.out.println("License-related comments count: " + licenseCommentCount);
    }
}
