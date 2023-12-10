public static boolean isPalindrome(String str) {
    // Remove all spaces, punctuation, and capitalization from the input string
    str = str.toLowerCase().replaceAll("[^a-zA-Z0-9]", "");

    // Check if the input string is a palindrome by comparing it to its reverse
    return str.equals(new StringBuilder(str).reverse().toString());
}
