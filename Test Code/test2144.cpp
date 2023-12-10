#include <torch/extension.h>

std::vector<at::Tensor> attn_score_backward(
    const at::Tensor &grad_output,
    const at::Tensor &attn_query,
    const at::Tensor &attn_keys,
    const at::Tensor &bias,
    const at::Tensor &linear_attn) {
    // Compute gradients of input tensors using chain rule and grad_output
    at::Tensor grad_attn_query = grad_output.matmul(linear_attn.transpose(0, 1));
    at::Tensor grad_attn_keys = grad_output.transpose(0, 1).matmul(attn_query).transpose(0, 1);
    at::Tensor grad_bias = grad_output.sum(0, true);
    at::Tensor grad_linear_attn = grad_output.transpose(0, 1).matmul(attn_query.transpose(0, 1));

    return {grad_attn_query, grad_attn_keys, grad_bias, grad_linear_attn};
}
