public class TextEncryptor {
    public String encrypt(String text, int shift) {
        StringBuilder encryptedText = new StringBuilder();
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (Character.isLetter(c)) {
                int newPos = (c - 'A' + shift) % 26;
                encryptedText.append((char) (newPos + 'A'));
            } else {
                encryptedText.append(c);
            }
        }
        return encryptedText.toString();
    }

    public String decrypt(String encryptedText, int shift) {
        StringBuilder decryptedText = new StringBuilder();
        for (int i = 0; i < encryptedText.length(); i++) {
            char c = encryptedText.charAt(i);
            if (Character.isLetter(c)) {
                int newPos = (c - 'A' - shift + 26) % 