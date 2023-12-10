public void processUnicodeLines(String[] inputLines, String origin) {
    for (String line : inputLines) {
        // Extract the code point and name from the line
        String[] parts = line.split(":");
        String codePoint = parts[0];
        String name = parts[1];

        // Convert the code point to its corresponding UTF-8 encoded text
        String utf8Text = ToUtf8Text(codePoint);

        // Send the messages to the specified destination
        srv.SendMsg(origin, "Code Point: " + codePoint);
        srv.SendMsg(origin, "Name: " + name);
        srv.SendMsg(origin, "UTF-8: " + utf8Text);
    }
}
