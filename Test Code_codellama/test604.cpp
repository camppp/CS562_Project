int mapKeys(int customKeyCode, int[][] keyMappings) {
    for (int i = 0; i < keyMappings.length; i++) {
        if (keyMappings[i][0] == customKeyCode) {
            return keyMappings[i][1];
        }
    }
    return -1;
}
