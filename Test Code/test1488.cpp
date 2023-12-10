java
public boolean processInput(String input) {
    if (recognizedCommands.contains(input)) {
        // Perform action corresponding to recognized command
        performAction(input);
        return true;
    } else {
        chatBox.addChat("Unrecognized command: " + input, errorColor);
        return false;
    }
}
