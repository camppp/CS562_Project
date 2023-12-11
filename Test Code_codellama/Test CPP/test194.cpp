class Frame {
    // ...
    vector<vector<bool>> sparkledBitFrame() {
        vector<vector<bool>> mask(height, vector<bool>(width));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j]) {
                    mask[i][j] = true;
                } else {
                    mask[i][j] = false;
                }
            }
        }
        return mask;
    }
};
