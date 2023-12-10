java
public int atoi(String str) {
    int index = 0, sign = 1, result = 0;
    // Discard leading whitespaces
    while (index < str.length() && str.charAt(index) == ' ') {
        index++;
    }
    // Handle optional plus or minus sign
    if (index < str.length() && (str.charAt(index) == '+' || str.charAt(index) == '-')) {
        sign = (str.charAt(index++) == '-') ? -1 : 1;
    }
    // Convert numerical digits to integer
    while (index < str.length() && Character.isDigit(str.charAt(index))) {
        int digit = str.charAt(index++) - '0';
        // Check for integer overflow
        if (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && digit > 7)) {
            return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        }
        result = result * 10 + digit;
    }
    return result * sign;
}
