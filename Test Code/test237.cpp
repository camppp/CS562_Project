string decryptMessage(string message, int offset) {
    string decryptedMessage = "";
    for (int i = 0; i < message.length(); i++) {
        int charCode = message[i] - offset;
        if (charCode < 32 || charCode > 126) {
            charCode = charCode % 95 + 32;
        }
        decryptedMessage += charCode;
    }
    return decryptedMessage;
}
