java
public class TextUpdater {
    public String updateText(String text, String oldWord, String newWord) {
        String[] words = text.split(" ");
        for (int i = 0; i < words.length; i++) {
            if (words[i].equalsIgnoreCase(oldWord)) {
                words[i] = newWord;
            }
        }
        return String.join(" ", words);
    }
}
