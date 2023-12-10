#include <vector>

std::vector<int> MTTKRP(const std::vector<std::vector<std::vector<int>>>& tensor, const std::vector<std::vector<int>>& matrix, int mode) {
    int I = tensor.size();
    int J = tensor[0].size();
    int K = tensor[0][0].size();
    int R = matrix[0].size();

    std::vector<int> result(I, 0);

    if (mode == 1) {
        for (int i = 0; i < I; i++) {
            for (int r = 0; r < R; r++) {
                int sum = 0;
                for (int j = 0; j < J; j++) {
                    for (int k = 0; k < K; k++) {
                        sum += tensor[i][j][k] * matrix[j][r];
                    }
                }
                result[i] += sum;
            }
        }
    } else if (mode == 2) {
        // MTTKRP along mode 2
    } else if (mode == 3) {
        // MTTKRP along mode 3
    }

    return result;
}
