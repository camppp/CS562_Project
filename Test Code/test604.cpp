java
int mapKeys(int customKeyCode, int[][] keyMappings) {
    for (int[] mapping : keyMappings) {
        if (mapping[0] == customKeyCode) {
            return mapping[1];
        }
    }
    return -1;
}
