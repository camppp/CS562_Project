int longestUniquePlaylist(int playlist[], int n) {
    int maxLength = 0;
    int currentLength = 0;
    int i = 0;
    while (i < n) {
        if (playlist[i] == playlist[i - 1]) {
            currentLength = 0;
        } else {
            currentLength++;
        }
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
        i++;
    }
    return maxLength;
}
