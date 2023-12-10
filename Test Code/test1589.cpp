java
import java.nio.charset.StandardCharsets;

public void processUnicodeLines(String[] inputLines, String origin) {
    for (String line : inputLines) {
        int colonIndex = line.indexOf(':');
        if (colonIndex != -1) {
            String codePointStr = line.substring(0, colonIndex);
            String name = line.substring(colonIndex + 1).trim();

            int codePoint = Integer.parseInt(codePointStr.substring(2), 16);
            String utf8Text = new String(Character.toChars(codePoint), StandardCharsets.UTF_8);

            srv.SendMsg(origin, "Code Point: " + codePointStr);
            srv.SendMsg(origin, "Name: " + name);
            srv.SendMsg(origin, "UTF-8: " + utf8Text);
        }
    }
}
