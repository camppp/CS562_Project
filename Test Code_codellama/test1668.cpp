vector<double> processLocations(vector<vector<double>>& loc, int line) {
    vector<double> avg_coords(6);
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < 6; j++) {
            avg_coords[j] += loc[i][j];
        }
    }
    for (int j = 0; j < 6; j++) {
        avg_coords[j] /= line;
    }
    return avg_coords;
}
