            // Initialize the matrixSum with the cumulative sum of elements
            matrixSum[0][0] = matrix[0][0];
            for (int i = 1; i < height; i++) {
                matrixSum[i][0] = matrixSum[i - 1][0] + matrix[i][0];
            }
            for (int j = 1; j < width; j++) {
                matrixSum[0][j] = matrixSum[0][j - 1] + matrix[0][j];
            }
            for (int i = 1; i < height; i++) {
                for (int j = 1; j < width; j++) {
                    matrixSum[i][j] = matrixSum[i - 1][j] + matrixSum[i][j - 1] - matrixSum[i - 1][j - 1] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return matrixSum[row2][col2];
        } else if (row1 == 0) {
            return matrixSum[row2][col2] - matrixSum[row2][col1 - 1];
        } else if (col1 == 0) {
            return matrixSum[row2][col2] - matrixSum[row1 - 1][col2];
        } else {
            return matrixSum[row2][col2] - matrixSum[row2][col1 - 1] - matrixSum[row1 - 1][col2] + matrixSum[row1 - 1][col1 - 1];
        }
    }
};
