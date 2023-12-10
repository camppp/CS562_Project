public boolean processInput(String input) {
    // Check if the input matches a recognized command
    if (input.equals("hello")) {
        // Perform the corresponding action for the "hello" command
        chatBox.addChat("Hello!", Color.GREEN);
        return true;
    } else if (input.equals("goodbye")) {
        // Perform the corresponding action for the "goodbye" command
        chatBox.addChat("Goodbye!", Color.RED);
        return true;
    }

    // If the input does not match any recognized command, add an error message to the chat interface
    chatBox.addChat("Sorry, I didn't understand that command. Try again!", Color.RED);
    return false;
}
