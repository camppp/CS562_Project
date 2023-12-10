#include <torch/torch.h>
#include <vector>

std::pair<torch::Tensor, torch::Tensor> process_data(const std::vector<std::pair<int, float>>& data) {
    std::vector<torch::Tensor> batch_idx;
    std::vector<torch::Tensor> batch_dist;

    for (const auto& out_pair : data) {
        batch_idx.push_back(torch::tensor(out_pair.first, torch::kInt32));
        batch_dist.push_back(torch::tensor(out_pair.second, torch::kFloat32));
    }
    auto out_idx = torch::stack(batch_idx);
    auto out_dist = torch::stack(batch_dist);
    return std::make_pair(out_idx, out_dist);
}
