public class StringUtil {
    public static Character firstNonNullOrNullChar(String t) {
        if (t == null || t.isEmpty()) {
            return null;
        }

        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (c!= '\u0000') {
                return c;
            }
        }

        return null;
    }
}