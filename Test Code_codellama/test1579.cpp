#include <iostream>
#include <vector>

std::vector<std::vector<int>> reverse_sequence(const std::vector<std::vector<int>>& input_sequence, int axis) {
    std::vector<std::vector<int>> output_sequence;

    if (axis == 0) {
        // Reverse each sequence within the input sequence
        for (int i = 0; i < input_sequence.size(); i++) {
            std::vector<int> reversed_sequence;
            for (int j = input_sequence[i].size() - 1; j >= 0; j--) {
                reversed_sequence.push_back(input_sequence[i][j]);
            }
            output_sequence.push_back(reversed_sequence);
        }
    } else if (axis == 1) {
        // Reverse each element within each sequence
        for (int i = 0; i < input_sequence.size(); i++) {
            std::vector<int> reversed_sequence;
            for (int j = input_sequence[i].size() - 1; j >= 0; j--) {
                reversed_sequence.push_back(input_sequence[i][j]);
            }
            output_sequence.push_back(reversed_sequence);
        }
    } else {
        // Invalid axis
        std::cout << "Invalid axis: " << axis << std::endl;
        return output_sequence;
    }

    return output_sequence;
}

int main() {
    std::vector<std::vector<int>> input_sequence = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int axis = 1;
    std::vector<std::vector<int>> output_sequence = reverse_sequence(input_sequence, axis);

    for (int i = 0; i < output_sequence.size(); i++) {
        for (int j = 0; j < output_sequence[i].size(); j++) {
            std::cout << output_sequence[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
