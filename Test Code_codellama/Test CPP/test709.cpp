class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        // Initialize the data structure with the given matrix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                sum[i][j] = matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // Calculate the sum of the elements within the rectangle
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            for (int j = col1; j <= col2; j++) {
                sum += sum[i][j];
            }
        }
        return sum;
    }

private:
    vector<vector<int>> sum;
};
