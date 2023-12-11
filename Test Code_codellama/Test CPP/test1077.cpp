#include <vector>
#include <iostream>

std::vector<int> MTTKRP(const std::vector<std::vector<std::vector<int>>>& tensor, const std::vector<std::vector<int>>& matrix, int mode) {
    // Check if the input is valid
    if (tensor.size() != matrix.size() || matrix.size() != mode) {
        std::cerr << "Invalid input" << std::endl;
        return {};
    }

    // Initialize the result vector
    std::vector<int> result(tensor.size());

    // Loop over the elements of the tensor and matrix
    for (int i = 0; i < tensor.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            // Compute the dot product of the current element of the tensor and the current row of the matrix
            int dotProduct = 0;
            for (int k = 0; k < tensor[i].size(); k++) {
                dotProduct += tensor[i][k] * matrix[j][k];
            }
            // Add the dot product to the result vector
            result[i] += dotProduct;
        }
    }

    return result;
}
