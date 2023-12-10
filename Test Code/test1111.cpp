++
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0;
    vector<int> charIndex(256, -1); // Initialize an array to store the index of each character's last occurrence
    int start = -1; // Initialize the starting index of the current substring

    for (int i = 0; i < n; i++) {
        if (charIndex[s[i]] > start) {
            start = charIndex[s[i]]; // Update the starting index if the character is repeated
        }
        charIndex[s[i]] = i; // Update the index of the current character
        maxLength = max(maxLength, i - start); // Update the maximum length of the substring
    }

    return maxLength;
}
