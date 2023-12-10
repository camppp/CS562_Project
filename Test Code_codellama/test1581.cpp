std::vector<std::vector<bool>> flipGrid(std::vector<std::vector<bool>> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int mid = arr[i].size() / 2;
        for (int j = 0; j < mid; j++) {
            arr[i][j] = !arr[i][j];
        }
        if (arr[i].size() % 2 == 1) {
            arr[i][mid] = !arr[i][mid];
        }
    }
    return arr;
}
