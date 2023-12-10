java
public static boolean isPalindrome(String str) {
    // Remove spaces and punctuation, and convert to lowercase
    String cleanStr = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
    
    // Check if the clean string is a palindrome
    int left = 0;
    int right = cleanStr.length() - 1;
    while (left < right) {
        if (cleanStr.charAt(left) != cleanStr.charAt(right)) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
