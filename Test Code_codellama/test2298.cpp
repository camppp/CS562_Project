#include <iostream>
#include <vector>
#include <snap/tensor.h>

class FullSortResult {
public:
    FullSortResult(snap::Tensor indices, snap::Tensor values, int axis) : indices(indices), values(values), axis(axis) {}

    std::tuple<snap::Tensor, snap::Tensor> perform_full_sort() {
        // Perform the full sort operation on the indices and values along the specified axis
        std::vector<int> sorted_indices;
        std::vector<float> sorted_values;
        for (int i = 0; i < indices.size(); i++) {
            sorted_indices.push_back(indices[i]);
            sorted_values.push_back(values[i]);
        }
        std::sort(sorted_indices.begin(), sorted_indices.end(), [&](int a, int b) {
            return values[a] < values[b];
        });
        return std::make_tuple(snap::Tensor(sorted_indices), snap::Tensor(sorted_values));
    }

private:
    snap::Tensor indices;
    snap::Tensor values;
    int axis;
};
