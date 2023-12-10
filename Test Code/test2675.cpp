java
public class WordConstants {
    public static boolean isTensedCopulaTypeVerb(String word) {
        // implementation of isTensedCopulaTypeVerb method
    }
}

public class WordModifier {
    public String appendPostmodifier(String word, String postmodifier) {
        if (WordConstants.isTensedCopulaTypeVerb(word)) {
            return word + postmodifier;
        } else {
            return word;
        }
    }
}
