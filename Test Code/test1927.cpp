java
public class TextUpdater {
    public String updateText(String text, String oldWord, String newWord) {
        String[] words = text.split("\\b");
        StringBuilder updatedText = new StringBuilder();

        for (String word : words) {
            if (word.equalsIgnoreCase(oldWord)) {
                if (Character.isUpperCase(word.charAt(0))) {
                    newWord = newWord.substring(0, 1).toUpperCase() + newWord.substring(1);
                }
                updatedText.append(newWord);
            } else {
                updatedText.append(word);
            }
        }

        return updatedText.toString();
    }
}
