java
public static String parseLicense(String readmeContent) {
    String[] lines = readmeContent.split("\n");
    for (String line : lines) {
        if (line.contains("MIT License")) {
            return "MIT";
        } else if (line.contains("Apache License")) {
            return "Apache";
        } else if (line.contains("GPL")) {
            return "GPL";
        } else if (line.contains("BSD")) {
            return "BSD";
        }
    }
    return "None";
}
