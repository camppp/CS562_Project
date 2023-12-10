java
public int shortestRepeatingSubstringLength(String s) {
    int n = s.length();
    for (int len = 1; len <= n / 2; len++) {
        if (n % len == 0) {
            String sub = s.substring(0, len);
            boolean valid = true;
            for (int i = len; i < n; i += len) {
                if (!sub.equals(s.substring(i, i + len))) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                return len;
            }
        }
    }
    return 0;
}
