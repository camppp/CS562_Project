public class TextEncryptor {
    public String encrypt(String text, int shift) {
        StringBuilder encryptedText = new StringBuilder();
        for (char c : text.toCharArray()) {
            if (Character.isLetter(c)) {
                char base = Character.isUpperCase(c)? 'A' : 'a';
                encryptedText.append((char) (base + (c - base + shift) % 26));
            } else {
                encryptedText.append(c);
            }
        }
        return encryptedText.toString();
    }

    public String decrypt(String encryptedText, int shift) {
        return encrypt(encryptedText, 26 - shift);
    }
}