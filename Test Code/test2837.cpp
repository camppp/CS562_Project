java
public String reverseWords(String s) {
    String[] words = s.trim().split("\\s+"); // Split the input string by whitespace and remove leading/trailing whitespace
    StringBuilder result = new StringBuilder();
    
    for (String word : words) {
        result.append(new StringBuilder(word).reverse()).append(" "); // Reverse each word and append it to the result
    }
    
    return result.toString().trim(); // Remove trailing whitespace and return the modified string
}
