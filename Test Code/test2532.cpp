java
import com.tangosol.util.extractor.IdentityExtractor;

public class LikeFilter {
    private final IdentityExtractor extractor;
    private final String pattern;

    private LikeFilter(IdentityExtractor extractor, String pattern) {
        this.extractor = extractor;
        this.pattern = pattern;
    }

    public static LikeFilter create(IdentityExtractor extractor, String pattern) {
        return new LikeFilter(extractor, pattern);
    }

    public boolean evaluate(String input) {
        return likeMatch(input, pattern);
    }

    private boolean likeMatch(String input, String pattern) {
        if (pattern.equals("%")) {
            return true;
        }
        if (input.isEmpty() && pattern.isEmpty()) {
            return true;
        }
        if (input.isEmpty() || pattern.isEmpty()) {
            return false;
        }
        if (pattern.charAt(0) == '%') {
            int index = pattern.indexOf('%', 1);
            if (index == -1) {
                return input.endsWith(pattern.substring(1));
            } else {
                String subPattern = pattern.substring(1, index);
                int subIndex = input.indexOf(subPattern);
                if (subIndex == -1) {
                    return false;
                }
                return likeMatch(input.substring(subIndex + subPattern.length()), pattern.substring(index));
            }
        } else if (pattern.charAt(0) == '_') {
            return likeMatch(input.substring(1), pattern.substring(1));
        } else {
            return input.charAt(0) == pattern.charAt(0) && likeMatch(input.substring(1), pattern.substring(1));
        }
    }
}
