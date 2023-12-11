java
public class LikeFilter {
    private final IdentityExtractor extractor;
    private final String pattern;

    public LikeFilter(IdentityExtractor extractor, String pattern) {
        this.extractor = extractor;
        this.pattern = pattern;
    }

    public boolean evaluate(String input) {
        String extractedInput = extractor.extract(input);
        return extractedInput.matches(pattern);
    }

    public static LikeFilter create(IdentityExtractor extractor, String pattern) {
        return new LikeFilter(extractor, pattern);
    }
}
